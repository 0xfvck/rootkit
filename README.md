# rootkit
A simple Rootkit made by me o hide files in Linux.

HOW TO USE: 

First, save the code into a file named hide_processes_files.c
Next, open up a terminal and navigate to the directory where you saved the file
Time to compile the code! Type gcc -o hide_processes_files hide_processes_files.c and hit enter
Once it's compiled, run the program by typing ./hide_processes_files and hitting enter again
This will hide the current process and file, and also add any additional hidden processes and files you specify with their corresponding PIDs and paths
If you want to hide a specific process, use the ocultar_proceso() function and give it the process ID and a name
To hide a specific file, use the ocultar_archivo() function and provide it the file path and a name
The program will keep hiding the processes and files as long as it's running, so sit back and relax
When you're ready to stop the program, use the kill command with the process ID (PID) of the hide_processes_files program
If you ever need to check out the list of hidden processes, use the mostrar_procesos_ocultos() function
