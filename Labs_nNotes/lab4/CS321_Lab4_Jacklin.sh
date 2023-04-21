#Lisa Jacklin
#CS 321 Lab 4
#4/15/2023
#############################################

#1: I used the chmod command to change the permission of the user, group, and others
#first, since we want to give the user full permissions in binary that is 111 == 7 
# and since we only want to give rx to others and groups, 011 == 3 is used in the
#rest of the command.
#note that I used filename inplace of an actual file

chmod 733 filename

#2:next three different instructions were used to set up FAT, NTFS, and EXT3 filesystem.
#these were mounted inside /mnt/ as myFat, myNTFS and myEXT3 respectively.

#custom directory for unique subdirectories within /mnt/
mkdir /mnt/myFat
mkdir /mnt/myNTFS
mkdir /mnt/myEXT3

#creating the file systems
dd if = /dev/zero of=fat-image.dd bs=1M count = 10 
dd if = /dev/zero of=ntfs-image.dd bs=1M count = 10
dd if = /dev/zero of=ntfs-image.dd bs=1M count = 10;

#initializing the filesystems with the .dd created
mkfs.fat fat-image.dd
mkfs.ntfs ntfs-image.dd
mkfs.ext3 ext3-image.dd

#then to mount the images
mount fat-image.dd   /mnt/myFat
mount ntfs-image.dd  /mnt/myNTFS
mount ext3-image.dd  /mnt/myEXT3

#3: now that the file systems are created we can use df to check that each has been created correctly.

df

#when using this command, you can see that these three file systems have the same values 
#since I set them to be such, and there is a lot of open space (in my case).

#4: to create users on a Linux system named testuser1, testuser2, and testuser3, the 
#following command was used:

adduser testuser1
adduser testuser2
adduser testuser3

#5: then a group was created called myfsuser

groupadd myfsuser

#6:now that a group myfsuser has been created, its time to add all three of the test users

usermod -a -G myfsuser testuser1
usermod -a -G myfsuser testuser2
usermod -a -G myfsuser testuser3

#7:since we are already within this group, we should be able to simply change the 
#access this group has to the myFAT directory

chmod 070 myFAT #note the zeros means no permissions unless part of the group

#8:now a short progam in shell taht can check if the current usr has write permissions to #the three directories made including separate print statements letting the user know.

#!/bin/bash
#since this code is referenced in Q9, lets call this program DirCheck.sh

# Define the directories to check and give a yes or no reply through echos
dir1="/mnt/myFat"
dir2="/mnt/myNTFS"
dir3="/mnt/myEXT3"

# Check write permissions for myFats
if [ -w "$dir1" ]
then
  echo "You have write access to myFats"
else
  echo "You do not have write access to myFats"
fi

# Check write permissions for myNTFS
if [ -w "$dir2" ]
then
  echo "You have write access to myNTFS"
else
  echo "You do not have write access to myNTFS"
fi

# Check write permissions for myEXT3
if [ -w "$dir3" ]
then
  echo "You have write access to myEXT3"
else
  echo "You do not have write access to myEXT3"
fi


#9:and lastly to adjust the ~./bashrc file so that the user will automatically get the #message after login.

#first, to achieve this, getting to the users home page
cd ~

#then you must open the .bashrc file so it can be edited
vi .bashrc

#and lastly, adding in the path of the shell file to the end of the file. This file happens #to be on my desktop at the moment so,

~/Desktop/DirCheck.sh

#then saving the edits through Ctrl+S and :Q! to exit out of the document.
#after making this adjustment, upon opening the users account, this file shall run
#telling the user that they have or don't have access to the three directories.


