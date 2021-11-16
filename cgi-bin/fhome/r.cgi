#!/usr/bin/perl

print "Content-type: text/html\n\n"; 

$dir = "/srv/ulyaoth/chat/public";   


opendir(ALLMAIL,"$dir/banlogs/");

 @dir = readdir(ALLMAIL);

 closedir(ALLMAIL);

print "<html>\n<head>\n<TITLE>ban logs</TITLE>\n";

print "</head>\n<body><h1>ban logs</h1>\n<hr>\n";



foreach $file(@dir){

if($file ne '.' && $file ne '..'){

print "Date: <a href=\"\/banlogs\/$file\"><b>$file</b></a><br>\n";

		}
			
}

print "<hr>\n</BODY></HTML>\n";