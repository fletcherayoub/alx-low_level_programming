#include <elf.h>
#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * _strncmp - compare two strings
 * @s1: first string
 * @s2: second string
 * @n: max number of bytes
 * Return: 0 if n s1 and s2 equal, otherwase non
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	for ( ; n && *s1 && *s2; --n, ++s1, ++s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
	}
	if (n)
	{
		if (*s1)
			return (1);
		if (*s2)
			return (-1);
	}
	return (0);
}

/**
 * len_magic - print
 * @buffer: buffer
 */
void len_magic(const unsigned char *buffer)
{
	unsigned int n;

	if (_strncmp((const char *) buffer, ELFMAG, 4))
	{
		write(STDERR_FILENO, "Error: Not ELF file\n", 23);
		exit(98);
	}
	printf("ELF Header:\n magic: ");
	for (n = 0; n < 16; n++)
		printf("%02x%c", buffer[n], n < 15 ? ' ' : '\n');
}

/**
 * len_class - print len_magic
 * @buffer : header ELF
 *
 * Return: 64 or 32
 */
size_t len_class(const unsigned char *buffer)
{
	printf("  %-34s ", "Class:");
	if (buffer[EI_CLASS] == ELFCLASS64)
	{
		printf("ELF64\n");
		return (64);
	}
	if (buffer[EI_CLASS] == ELFCLASS32)
	{
		printf("ELF32\n");
		return (32);
	}
	printf("<unknown: %x>\n", buffer[EI_CLASS]);
	return (32);
}

/**
 * len_abivers - print
 * @buffer: ELF
 */
void len_abivers(const unsigned char *buffer)
{
	printf("  %-34s %u\n", "ABI version:", buffer[EI_ABIVERSION]);
}

/**
 * len_data - print
 * @buffer: ELF buffer
 *
 * Return: 1 if big endian, otherwase 0
 */
int len_data(const unsigned char *buffer)
{
	printf("  %-34s ", "Data:");
	if (buffer[EI_DATA] == ELFDATA2MSB)
	{
		printf("2's complement, big endian\n");
		return (1);
	}
	if (buffer[EI_DATA] == ELFDATA2LSB)
	{
		printf("2's complement, little endian\n");
		return (0);
	}
	printf("Invalid data encoding\n");
	return (0);
}

/**
 * len_version - print ELF version
 * @buffer: buffer ELF
 */
void len_version(const unsigned char *buffer)
{
	printf("  %-34s %u", "version:", buffer[EI_VERSION]);

	if (buffer[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * len_osabi - print ELF OS/ABI
 * @buffer: ELF buffer
 */
void len_osabi(const unsigned char *buffer)
{
	const char *osabi_table[19] = {
		"UNIX - System V", "UNIX - HP-UX", "UNIX - NetBSD",
		"UNIX - GNU", "<unknown: 4>", "<unknown: 5>", "UNIX - Solaris",
		"UNIX - AIX", "UNIX - IRIX", "UNIX - FreeBSD", "UNIX - TRU64",
		"Novell - Modesto", "UNIX - OpenBSD", "VMS - OpenVMS",
		"HP - Non-Stop Kernel", "AROS", "FenixOS",
		"Nuxi CloudABI", "Stratus Technologies OpenVOS"
	};

	printf(" %-34s", "OS/ABI:");

	if (buffer[EI_OSABI] < 19)
		printf("%s\n", osabi_table[(unsigned int) buffer[EI_OSABI]]);
	else
		printf("<unknown: %x>\n", buffer[EI_OSABI]);
}

/**
 * len_type - print len_type
 * @buffer: ELF buffer
 * @endian: endianness
 */
void len_type(const unsigned char *buffer, int endian)
{
	char *type_table[5] = {
		"NONE (No file type)",
		"REL (Relocatable file)",
		"EXEC (Executable file)",
		"DYN (Shared object file)",
		"CORE (Core file)"
	};
	unsigned int type;

	printf("  %-34s ", "type:");

	if (endian)
		type = 0x100 * buffer[16] + buffer[17];
	else
		type = 0x100 * buffer[17] + buffer[16];

	if (type < 5)
		printf("%s\n", type_table[type]);
	else if (type >= ET_LOPROC && type <= ET_HIPROC)
		printf("Processor Specific: (%4x)\n", type);
	else if (type >= ET_LOOS && type <= ET_HIOS)
		printf("OS Specific: (%4x)\n", type);
	else
		printf("<unknown: %x>\n", type);
}

/**
 * len_entry - entry point address
 * @buffer: string contraining the entry point address
 * @l_mode: (32, 64)
 * @endian: endianness
 */
void len_entry(const unsigned char *buffer, size_t l_mode, int endian)
{
	int a_size = l_mode / 8;

	printf("  %-34s 0x", "Entry point address:");
	if (endian)
	{
		while (a_size && !*(buffer))
			--a_size, ++buffer;

		printf("%x", *buffer & 0xff);

		while (--a_size > 0)
			printf("%02x", *(++buffer) & 0xff);
	}
	else
	{
		buffer += a_size;
		while (a_size && !*(--buffer))
			--a_size;

		printf("%x", *buffer & 0xff);
		while (--a_size > 0)
			printf("%02x", *(--buffer) & 0xff);
	}
	printf("\n");
}

/**
 * _close - close a file descriptor and print
 * @ld: file descriptor
 */
void _close(int ld)
{
	if (close(ld) != -1)
		return;
	write(STDERR_FILENO, "Error: Can't close ld\n", 22);
	exit(98);
}

/**
 * _read - read
 * @ld: descriptor to read
 * @buf: buffer to write
 * @c: bytes
 */
void _read(int ld, char *buf, size_t c)
{
	if (read(ld, buf, c) != -1)
		return;
	write(STDERR_FILENO, "Error: Can't read from file\n", 28);
	_close(ld);
	exit(98);
}

/**
  * main - copy a file contents to another file
  * @ac: arguments count
  * @av: arguments value
  *
  * Return: 0 success
  */
int main(int ac, const char *av[])
{
	unsigned int l_mode;
	int endian;
	int ld;
	unsigned char buffer[18];

	if (ac != 2)
	{
		write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
		exit(98);
	}
	ld = open(av[1], O_RDONLY);
	if (ld == -1)
	{
		write(STDERR_FILENO, "Error: can't read from file\n", 28);
		exit(98);
	}
	_read(ld, (char *) buffer, 18);
	len_magic(buffer);
	l_mode = len_class(buffer);
	endian = len_data(buffer);
	len_version(buffer);
	len_osabi(buffer);
	len_abivers(buffer);
	len_type(buffer, ld);
	lseek(ld, 24, SEEK_SET);
	_read(ld, (char *) buffer, l_mode / 8);
	len_entry(buffer, l_mode, endian);
	_close(ld);

	return (0);
}
