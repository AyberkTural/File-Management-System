#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void createfile(){

        char create [10000];

        FILE * fptr;

        printf("Enter the pathway of file that you want to create : \n");

        scanf("%s",create);

        fptr = fopen(create,"w");


    if (fptr == NULL) {

        printf("Error opening file\n");

        return 1;

    }

    fprintf(fptr, "Code name Pathfinder.\n");

    // Close the file
    fclose(fptr);

}

void append() {

   FILE * fptr;

  int i,n;

  char str[10000];

  char filename[10000];

  char str1;

    printf(" Input the file name to be opened : ");

	scanf("%s",filename);

	char lastThree[4];

    int length = strlen(filename);

    strncpy(lastThree, &filename[length - 3], 3);

    lastThree[3] = '\0';

    if (strcmp(lastThree,"txt") == 0) {

            fptr = fopen(filename, "a");

    printf(" Input the number of lines to be written : ");

    scanf("%d", &n);

    printf(" The lines are : \n");

    for(i = 0; i < n+1;i++)

    {

    fgets(str, sizeof str, stdin);

    fputs(str, fptr);

  }

  fclose (fptr);

	fptr = fopen (filename, "r");

	printf("The content of the file %s is  :\n",filename);

	str1 = fgetc(fptr);

	while (str1 != EOF)

		{

			printf ("%c", str1);

			str1 = fgetc(fptr);

		}

    fclose (fptr);

    }

    else {

         printf("You can apply only text files this function.");

    }

}

void deletefile(){

        char deletingfile[10000] ;

        printf("Enter the pathway of the file that you want to delete : \n");

        scanf("%s",deletingfile);

        int deleting = remove(deletingfile);

        if (!deleting) {

      printf("The file is deleted.");

      }

     else {

      printf("the file is not deleted.");

      }

}

void renamethefile(){

    char old_name[1000];

    char new_name[1000];

    printf("Enter the pathway of the file that you want to change name : \n");

    scanf("%s",&old_name);

    printf("Enter the new name of file with pathway : \n");

    scanf("%s",&new_name);

    if (rename(old_name, new_name) != 0) {

        printf("Error renaming file.\n");

    }

    else {

        printf("File renamed successfully.\n");

    }

}

void copyfile() {

   char ch, source_file[1000], target_file[1000];

   FILE *source,*target;

   printf("Enter name of file to copy\n");

   gets(source_file);

   source = fopen(source_file, "r");

   if( source == NULL )

   {
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }

   printf("Enter name of target file\n");

   gets(target_file);

   target = fopen(target_file, "w+");

   if( target == NULL )
   {
      fclose(source);
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }

   while( ( ch = fgetc(source) ) != EOF )

      fputc(ch, target);

   printf("File copied successfully.\n");

   fclose(source);

   fclose(target);

}

void movefile() {

    char oldPath[1000] = "";

    char newPath[1000] = "";

    /*E:\2023Spring\SOFT3122\openfile*/

    printf("Enter the pathway of the file that you want to change name : \n");

    scanf("%s",&oldPath);

    printf("Enter the new name of file with pathway : \n");

    scanf("%s",&newPath);


    if (rename(oldPath, newPath) == 0) {

        printf("File moved successfully.");

    }

    else {

        printf("Error: unable to move the file.");

    }

}

void insertTextInFileSpecificPosition() {

    char filename[10000];

    printf("Enter the name of the file: ");

    scanf("%s", filename);

    char lastThree[4];

    int length = strlen(filename);

    strncpy(lastThree, &filename[length - 3], 3);

    lastThree[3] = '\0';

    if(strcmp(lastThree,"txt") == 0) {

    long position;

    printf("Enter the position: ");

    scanf("%ld", &position);

    while (getchar() != '\n');

    char text_to_insert[10000];

    printf("Enter the text: \n");

    scanf("%[^\n]", text_to_insert);

    FILE* file = fopen(filename, "r");

    if (file == NULL) {

        printf("Unable to open the file.\n");

        return;

    }

    fseek(file, 0, SEEK_END);

    long file_size = ftell(file);

    fseek(file, 0, SEEK_SET);

    char* content = (char*)malloc((file_size + 1) * sizeof(char));

    if (content == NULL) {

        printf("Memory allocation failed.\n");

        fclose(file);

        return;
    }

    size_t bytes_read = fread(content, sizeof(char), file_size, file);

    content[bytes_read] = '\0';

    fclose(file);

    if (position > bytes_read || position < 0) {

        printf("Invalid position.\n");

        free(content);

        return;

    }

    long modified_size = bytes_read + strlen(text_to_insert);

    char* modified_content = (char*)malloc((modified_size + 1) * sizeof(char));

    if (modified_content == NULL) {

        printf("Memory allocation failed.\n");

        free(content);

        return;

    }

    strncpy(modified_content, content, position);

    modified_content[position] = '\0';

    strcat(modified_content, text_to_insert);

    strcat(modified_content, content + position);

    file = fopen(filename, "w");

    if (file == NULL) {

        printf("Unable to open the file.\n");

        free(content);

        free(modified_content);

        return;

    }

    size_t bytes_written = fwrite(modified_content, sizeof(char), modified_size, file);

    if (bytes_written != modified_size) {

        printf("Failed to write the modified content.\n");

    }

    fclose(file);

    free(content);

    free(modified_content);

    printf("Text inserted successfully.\n");
}

else {

    printf("You can apply only text files this function.");

}

}

void removeAllTextFromFile() {

    char filename[10000];

    printf(" Input the file name to be opened : \n");

	scanf("%s",&filename);

    char lastThree[4];

    int length = strlen(filename);

    strncpy(lastThree, &filename[length - 3], 3);

    lastThree[3] = '\0';

    if(strcmp(lastThree,"txt") == 0) {


    FILE* file = fopen(filename, "w");

    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    fclose(file);

    printf("All text removed from the file successfully.\n");

    }

     else {

         printf("You can apply only text files this function.");

    }

}

void showContent() {

  char file_path[10000] ;

  int lines_per_page;

  printf("Enter the file path : \n");

  scanf("%s",file_path);

   char lastThree[4];

    int length = strlen(filename);

    strncpy(lastThree, &filename[length - 3], 3);

    lastThree[3] = '\0';

    if(strcmp(lastThree,"txt") == 0) {

  printf("Enter the number of lines per page : \n");

  scanf("%d",&lines_per_page);

    FILE* file = fopen(&file_path, "r");

    if (file == NULL) {

        printf("Failed to open the file.\n");

        return;

    }

    int line_count = 0;

    char buffer[10000];

    while (fgets(buffer, sizeof(buffer), file)) {

        printf("%s", buffer);

        line_count++;

        if (line_count % lines_per_page == 0) {

            printf("Press Enter to continue...\n");

            while (getchar() != '\n');

        }
    }

    fclose(file);
}

 else {

         printf("You can apply only text files this function.");

    }

}

void printHelp() {

    printf("Available commands:\n");

    printf("create - Create a new file\n");

    printf("delete - Delete an existing file\n");

    printf("rename - Rename an existing file\n");

    printf("copy - Copy a file\n");

    printf("move - Move a file from one folder to another\n");

    printf("append - Append text to the end of a file\n");

    printf("insert - Insert text in a specific position within the file\n");

    printf("remove - Remove all text present in a file\n");

    printf("show - Show the content of a text data store\n");

    printf("help - Display available commands\n");

    printf("exit - Exit the program\n");

}
int main() {

     char command[100];

    while (1) {
        printf("Enter a command (type 'help' for a list of commands): ");
        scanf("%s", command);

        if (strcmp(command, "help") == 0) {

              printHelp();

        } else if (strcmp(command, "create") == 0) {

            createfile();

        } else if (strcmp(command, "delete") == 0) {

          deletefile();

        } else if (strcmp(command, "rename") == 0) {

           renamethefile();

        } else if (strcmp(command, "copy") == 0) {

            copyfile();

        } else if (strcmp(command, "move") == 0) {

           movefile();

        } else if (strcmp(command, "append") == 0) {

          append();

        } else if (strcmp(command, "insert") == 0) {

           insertTextInFileSpecificPosition();

        } else if (strcmp(command, "removeall") == 0) {

            removeAllTextFromFile();

        } else if (strcmp(command, "show") == 0) {

          showContent();

        } else if (strcmp(command, "quit") == 0) {

            break;

        }

        else

        {
            printf("Invalid command. Type 'help' for a list of commands.\n");
        }
    }

    return 0;
}
