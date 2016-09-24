 # Включить < stdio.h >
# Включить < stdlib.h >
# Включают < SYS / types.h >
# Включают < SYS / wait.h >
# Включить < unistd.h >
# Определение MAX_WORDS 16
# Определить MAX_LINE 80

Int главный ()
{
INT inword = 0 , г = 0 , J = 0 , ч;
символ буфера [MAX_WORDS] [MAX_LINE];
символ * ARGV [MAX_WORDS];

Printf ( " $ " );

в то время как ((ч = GetChar ())! = EOF) {
если (ч == ' ' || ч == ' \ п ' ) {
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
если (ч == ' \ п ' ) {
ARGV [я] = NULL ;
pid_t PID = вилка ();
если (! ИДП) {
// Ребенок филиал
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
Printf ( " $ " ); 
}

}
Printf ( " \ п " );
вернуть EXIT_SUCCESS;
}
