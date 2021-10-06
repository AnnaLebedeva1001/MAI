#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    struct stat buf;
    if (argc != 3)
    {
        printf("3 parameters required\n");
        return -1;
    }
    symlink(argv[1], argv[2]);
    lstat(argv[2], &buf);
    printf("устройство - %d\n"
    "inode - %d\n"
    "режим доступа - %d\n"
     "количество жестких ссылок - %d\n"
    "ID пользователя-владельца - %d\n"
    "ID группы-владельца - %d\n"
    "тип устройства - %d\n"
    "общий размер в байтах - %d\n"
    "размер блока ввода-вывода - %d\n"
    "количество выделенных блоков - %d\n"
    "время последнего доступа - %d\n"
    "время последней модификации - %d\n"
    "время последнего изменения - %d\n",
           buf.st_dev, buf.st_ino,
           buf.st_mode, buf.st_nlink, buf.st_uid, buf.st_gid, buf.st_rdev, buf.st_size, buf.st_blksize,
           buf.st_blocks, buf.st_atime, buf.st_mtime, buf.st_ctime);
    return 0;
}