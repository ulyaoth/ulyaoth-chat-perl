#!/usr/bin/perl

if($command eq '/vcomm' && $level < $comm_rank){

$errors = " Error, command $command not recognized, please use /help for a list of commands.";
        
return $errors;

exit;

}

print "Content-type: text/html\n\n";

require "$root/inc/print_header.inc";

print "<center><b> ~§ Committee Board §~ </b></center> <p>";

open(COMMBOARD,"$root/boards/commbb.txt");

@postfile = <COMMBOARD>;

@postfile = reverse(@postfile);

close(COMMBOARD);

$s = 0;

foreach $p(@postfile){

$s++;

($p1,$p2)=split(/\|\"\'\|/,$p);

$p2 =~ s/^\<!-- (([^ >]|\n)*) -->//ig;


print "<b><a href=\"$location?n=$DATA{'n'}&room=$room&id=$DATA{'id'}&msg=/commbbclear+$p1\">DEL</a></b> | $p2";

}

print "TOTAL: $s post(s).<br>\n";

require "$root/inc/check_pm.inc";

require "$root/inc/print_footer.inc";

exit;