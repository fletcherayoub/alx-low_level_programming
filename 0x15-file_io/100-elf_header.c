#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void len_magic(char *);
int len_class(char *);
void len_entry(char *, int, int);
int len_data(char *);
void len_version(char *);
void len_osabi(char *);
void len_abivers(char *);

 /**
  * main - check code
  * @ac: arguments count
  * @av: arguments vactor
  * Return: 0 success otherwise failed
  */
int main(int ac, char **av)
{
	int fl, nl, l_class, l_da;
	char buffer[18];

	if (ac != 2)
	{
		write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
		exit(98);
	}
	fl = open(av[1], O_RDONLY);
	if (fl == -1)
	{
		write(STDERR_FILENO, "Error: can't open  from file\n", 28);
		exit(98);
	}
	nl = read(fl, buffer, 18);
	if (nl == -1)
	{
		write(STDERR_FILENO, "Error: can't read from file\n", 28);
		exit(98);
	}
	len_magic(buffer);
	l_class = len_class(buffer);
	l_da = len_data(buffer);
	len_version(buffer);
	len_osabi(buffer);
	len_abivers(buffer);
	len_type(buffer, l_da);
	lseek(fl, 24, SEEK_SET);
	read(fl, (char *) buffer, l_class / 8);
	len_entry(buffer, l_class, l_da);
	if (close(fl) == -1)
	{
		write(STDERR_FILENO, "Error: cannot close\n", 20);
		exit(98);
	}
	return (0);
}
/**
 * len_magic - print
 * @buffer: buffer
 */
void len_magic(char *buffer)
{
int n;

if ((buffer[0] != 127) || (buffer[1] != 'E')
|| (buffer[2] != 'L' || (buffer[3] != 'F'))
write(STDERR_FILENO, "Error: not ELF file\n", 20);
exit(98);
}
printf("ELF Header:\n len_magic: ");
for (i = 0; i < 16; i++)
{
printf(" %.2x", buffer[n];
}
printf("\n");
}

/**
 * len_class - print len_magic
 * @buffer : header ELF
 * Retrurn: 64 or 32
 */
int len_class(char *buffer)
{
printf("%-35s", "len_Class:");

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
void len_abivers(char *buffer)
{
	printf(" %-35s%u\n", "ABI version:", buffer[EI_ABIVERSION]);
}
/**
 * len_data - print
 * @buffer: ELF buffer
 *
 * Return: 1 if big endian, otherwase 0
 */
int len_data(char *buffer)
{
	printf(" %-35s", "len_Data:");

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
	printf("Invalid data encording\n");
	return (0);
}

/**
 * len_version - print ELF version
 * @buffer: buffer ELF
 */
void len_version(char *buffer)
{
	printf(" %-35s%u", "version:", buffer[EI_VERSION]);
	if (buf[EI_VERSION] == EV_CURRENT && 1)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * len_osabi - print ELF OS/ABI
 * @buffer: ELF buffer
 */
void len_osabi(char *buffer)
{
	char *table[19] = {
		"UNIX - System V", "UNIX - HP-UX", "UNIX - NetBSD",
		"UNIX - GNU", "<unknown: 4>", "<unknown: 5>", "UNIX - Solaris",
		"UNIX - AIX", "UNIX - IRIX", "UNIX - FreeBSD", "UNIX - TRU64",
		"Novell - Modesto", "UNIX - OpenBSD", "VMS - OpenVMS",
		"HP - Non-Stop Kernel", "AROS", "FenixOS",
		"Nuxi CloudABI", "Stratus Technologies OpenVOS"}
	printf(" %-35s", "OS/ABI:");
	if (buffer[EI_OSABI] < 19)
		printf("%s\n", table[(unsigned int) buffer[EI_OSABI]]);
	else
		printf("<unknown: %x>\n", buffer[EI_OSABI]);
}
/**
 * len_type - print len_type
 * @buffer: ELF buffer
 * @endian: endianness
 */
void len_type(char *buffer, int endian)
{
	int len_type;

	char *table[5] = {
		"NONE (No file type)",
		"REL (Relocatable file)",
		"EXEC (Executable file)",
		"DYN (Shared object file)",
		"CORE (Core file)"
	};

	printf(" %-35s", "len_type:");

	if (endian)
		len_type = 256 * buffer[16] + buffer[17];
	else
		len_type = 256 * buffer[17] + buffer[17];

	if (len_type < 5)
		printf("%s\n", table[len_type]);
	else if (len_type >= ET_LOPROC && len_type <= ET_HIPROC)
		printf("Processor Specific: (%4x)\n", len_type);
	else if (len_type >= ET_LOOS && len_type <= ET_HIOS)
		printf("OS Specific: (%4x)\n", len_type);
	else
		printf("<unknown: %x>\n", len_type);
}
/**
 * len_entry - entry point address
 * @buffer: string contraining the entry point address
 * @m: (32, 64)
 * @e: endianness
 */
void len_entry(char *buffer, int m, int e)
{
	int lk = m / 8;

	printf(" %-35s0x", "Entry point address:");
	if (e)
	{
		while (lk && !*(buffer))
		{
			++buffer;
			--lk;
		}
		printf("%x", *buffer & 0xff);

		while (--lk > 0)
			printf("%02x", *(++buffer) & 0xff);
	}
	else
	{
		buffer += lk;
		while (lk && !*(--buffer))
			--lk;
		printf("%x", *buffer & 0xff);
		while (--lk > 0)
			printf("%02x", *(--buffer) & 0xff);
	}
	printf("\n");
}


