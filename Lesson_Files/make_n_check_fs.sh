#Use the df command to display information about total space and available space on a file system. The FileSystem parameter specifies the name of the device on which the file system resides, the directory on which the file system is mounted, or the relative path name of a file system.
df -h

#Create a FAT file system
dd if=/dev/zero of=fat-image.dd bs=1M count=10 #Create a new disk 10 MB image

mkfs.fat fat-image.dd #Initialize it with a file system

mkdir /mnt/my-fat-fs #Create a unique mount point

mount fat-image.dd /mnt/my-fat-fs #Mount the image
#Now, /mnt/my-fat-fs is a readable/writable part of your computer’s file system.

#Now, check how much free space is available on that mount point. df or the like will help here. (use df command and locate the file system)

umount /mnt/my-fat-fs #Unmount the partition


#Create an NTFS file system and repeat the steps above
dd if=/dev/zero of=ntfs-image.dd bs=1M count=10 #Create a new disk 10 MB image (same as last section. Just use a different name for the image)
mkfs.ntfs ntfs-image.dd --force #Initialize it with a NTFS file system (--force may be necessary to create the file system forcefully)
#Rest of the steps are all same
#Check how much dish space are available for FAT and NTFS system

#DO the same for ext3



#Reading:
#Difference between different ext-x: https://www.learnitguide.net/2016/08/difference-between-ext2-ext3-and-ext4.html
#Difference between FAT and NTFS: https://www.geeksforgeeks.org/difference-between-fat32-and-ntfs/
