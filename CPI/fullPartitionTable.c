#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MBR_SIZE 446
#define PARTITION_TABLE_SIZE 16

struct partition
{
        unsigned char boot_flag;        
        unsigned char chs_begin[3];
        unsigned char sys_type;         
        unsigned char chs_end[3];
        unsigned char start_sector[4];
        unsigned char nr_sector[4];
};

void string_in_hex(void *in_string, int in_string_size);
void dump_partition(struct partition *part, int partition_number);

void dump_partition(struct partition *part, int partition_number)
{        
        printf("boot_flag = %02X\n", part->boot_flag);
        printf("chs_begin = ");
        string_in_hex(part->chs_begin, 3);
        printf("sys_type = %02X\n", part->sys_type);
        printf("chs_end = ");
        string_in_hex(part->chs_end, 3);
        printf("start_sector = ");
        string_in_hex(part->start_sector, 4);
        printf("nr_sector = ");
        string_in_hex(part->nr_sector, 4);
}

void string_in_hex(void *in_string, int in_string_size)
{
        int i;
        int k = 0;
        for (i = 0; i < in_string_size; i++)
        {
                printf("%02x ", ((char *)in_string)[i]& 0xFF);
                k = k + 1;
                if (k == 16)
                {
                        printf("\n");
                        k = 0;
                }
        }
        printf("\n");
}

int main()
{
        int i = 1, nr = 0, pos = -1,k=0,fd = 0;
        char  buf[512];
        struct partition *sp;        
        if ((fd = open("/dev/sda", O_RDONLY | O_SYNC)) == -1)
        {
                perror("Open");
                exit(1);
        }        
        pos = lseek (fd, 0, SEEK_CUR);        
        if ((nr = read(fd, buf, sizeof(buf))) == -1)
        {
                perror("Read");
                exit(1);
        }
        close(fd);  
        // printing partion table       
        for (i = 446; i < 512; i++)
        {
                printf("%02x ", ((char *)buf)[i]& 0xFF);
                k = k + 1;
                if (k == 16)
                {
                        printf("\n");
                        k = 0;
                }
        }
        printf("\nSize of MBR = %lu byte \nSize of Partion Table 4*16 byte\n", sizeof(buf));        
        printf("\t----------------------------------\n");
        printf("\t----Partition Table (dev/sda1)----\n");
        printf("\t----------------------------------\n");
        int offset=0;
        sp = (struct partition *)(buf + MBR_SIZE + (PARTITION_TABLE_SIZE * offset));                
        dump_partition(sp,1);        
        return 0;
}