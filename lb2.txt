# Включить < stdio.h >
# Включить < stdlib.h >
# Включают < SYS / types.h >
# Включают < SYS / wait.h >
# Включить < unistd.h >
# Включить < fcntl.h >
# Определение MAX_WORDS 16
# Определить MAX_LINE 80

Int главный () {
Int я = 0 , J = 0 , ч, inword = 0 , STDOUT_FORWARD = 0 , STDIN_FORWARD = 0 ;
символ буфера [MAX_WORDS] [MAX_LINE];
символ * ARGV [MAX_WORDS];

Printf ( " $ " );

в то время как ((ч = GetChar ())! = EOF) {
если (ч == ' ' || ч == ' \ п ' || ч == ' > ' || ч == ' < ' ) {
если (inword == 1 ) {
inword = 0 ;
буфер [I] [J] = ' \ 0 ' ;
ARGV [я] = буфер [я]; 
++ Я; 
J = 0 ; 
}
}
еще {
буфер [I] [J] = ч; 
++ J; 
inword = 1 ; 
}

если (ч == ' > ' ) {
STDOUT_FORWARD = я;
}
если (ч == ' < ' ) {
STDIN_FORWARD = я;
}

если (ч == ' \ п ' ) {
ARGV [я] = NULL ;
pid_t PID = вилка ();
если (! ИДП) {
// Ребенок филиал
если (! STDOUT_FORWARD) {
INT FD = открыт (ARGV [STDOUT_FORWARD], O_WRONLY | O_CREAT | O_TRUNC, 0666 );
если (== FD - 1 ) {
PError ( " открыть " );
вернуть EXIT_FAILURE; 
}

если (- 1 == dup2 (FD, STDOUT_FILENO)) {
PError ( " dup2 " );
вернуть EXIT_FAILURE; 
}
ARGV [STDOUT_FORWARD] = NULL ;
}

если (! STDIN_FORWARD) {
INT fd1 = открыт (ARGV [STDIN_FORWARD], O_RDONLY);
если (fd1 == - 1 ) {
PError ( " открыть " );
вернуть EXIT_FAILURE; 
}
если (- 1 == dup2 (fd1, STDIN_FILENO)) {
PError ( " dup2 " );
вернуть EXIT_FAILURE; 
}
ARGV [STDIN_FORWARD] = NULL ;
}
INT с.в. = execvp (ARGV [ 0 ], ARGV);
если (ПЖ == - 1 ) {
PError ( " execvp " );
вернуть EXIT_FAILURE; 
} 
}
// Родительский филиал
PID = ожидание ( NULL );
если (PID == - 1 ) {
PError ( " ждать " );
вернуть EXIT_FAILURE;
} 
inword = 0 ;
I = 0 ;
J = 0 ;
STDOUT_FORWARD = 0 ;
STDIN_FORWARD = 0 ;
Printf ( " $ " ); 
}
}
Printf ( " \ п " );
вернуть EXIT_SUCCESS;
}




