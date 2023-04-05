#Create a test user
adduser testuser

#Create a group
groupadd testgroup

#See all the groups
cat /etc/group

#Add a user to a group
usermod -a -G testgroup testuser

#Create a file and add some content to it
vi testFile.txt

#Check the permission
ls -lh testFile.txt

#Give all permission to everyone
chmod 777 testFile.txt #chmod rwxrwxrwx filename (rwx #1: for current user)

#How can you give only readonly permission to the current user

