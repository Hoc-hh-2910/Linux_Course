#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miniz.h"

#define ZIP_PATH "/home/hochh/Linux_Course/kernel_project/kernel/kernel.zip" // Đường dẫn đến file ZIP
#define SIZE_USER_MAX 50
#define SIZE_PASSWORD_MAX 50
#define SIZE_OUTPUT 100

const char *out = NULL;
const char *filename = "users.txt";

void read_file_in_zip(const char *zip_path, const char *file_name) {

    // Read Zip file
    mz_zip_archive zip;
    memset(&zip, 0, sizeof(zip));

    if (!mz_zip_reader_init_file(&zip, zip_path, 0)) {
        printf("Cannot open ZIP file: %s\n", zip_path);
        return;
    }

    // Find file in Zip
    int file_index = mz_zip_reader_locate_file(&zip, file_name, NULL, 0);
    if (file_index < 0) {
        printf("Can not find %s in ZIP\n", file_name);
        mz_zip_reader_end(&zip);
        return;
    }

    // Read content file
    size_t file_size;

    out = (char *)mz_zip_reader_extract_file_to_heap(&zip, file_name, &file_size, 0);
    if (!out) {
        printf("Can not read in ZIP\n");
        mz_zip_reader_end(&zip);
        return;
    }

    return ;
    // Close ZIP
    mz_zip_reader_end(&zip);

}

int check_login(const char *out_put, const char *user, const char *password)
{
    char *file_user;
    char *file_password;

    file_user = strtok((char*) out_put,"|");
    file_password = strtok(NULL, "|");

    if(strcmp(file_user,user) == 0 && strcmp(file_password,password) == 0){

        return 1;
    }

    return 0;
}

void access_permission(){

    system("unzip -d /home/hochh/Linux_Course/kernel_project/kernel/ /home/hochh/Linux_Course/kernel_project/kernel/kernel.zip users.txt");

    FILE *file = fopen("/home/hochh/Linux_Course/kernel_project/kernel/users.txt", "w");
    if(file == NULL) {
        printf("Error: Can not open users.text!\n");
        return ;
    }

    fprintf(file, "admin|1234|1\n");

    system("zip -u /home/hochh/Linux_Course/kernel_project/kernel/kernel.zip /home/hochh/Linux_Course/kernel_project/kernel/users.txt");
    printf("Accept access permisiion!\n");

    printf("Extracting! ...\n");
    system("unzip -d /home/hochh/Linux_Course/kernel_project/kernel/ /home/hochh/Linux_Course/kernel_project/kernel/kernel.zip kernel.c");
    printf("Compiling! ...\n");
    system("gcc /home/hochh/Linux_Course/kernel_project/kernel/kernel.c -o /home/hochh/Linux_Course/kernel_project/kernel/kernel");
    printf("Run Kernel! ...\n");
    system("/home/hochh/Linux_Course/kernel_project/kernel/kernel");

}

int main() {
    
    char user[SIZE_USER_MAX];
    char password[SIZE_PASSWORD_MAX];

    // Open Zip file and read "users.txt"

    read_file_in_zip(ZIP_PATH, filename);

    while(1){
        // Login 
        printf("Log in: \n");

        printf("Account: ");
        scanf("%s", user);
        printf("Password: ");
        scanf("%s", password);
        
        if(check_login(out,user,password)){
            printf("Log in Successful!\n");
            break;
        }
        else{
            printf("Wrong Account or Password, Please try agian!\n");
        }
    }

    access_permission();

    return 0;
}


