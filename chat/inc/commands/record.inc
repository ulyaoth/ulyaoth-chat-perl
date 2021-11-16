#!/usr/bin/perl

if ($command eq '/record' && $level < $comm_rank){


$errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;


}



print "Content-type: text/html\n\n";

require "$root/inc/print_header.inc";

open(OPBOARD,"$root/boards/record.txt");

@postfile = <OPBOARD>;


@w = reverse(@postfile);



@s = @w[0..100];



@print_again = reverse(@s);



open(PRINTBOARD, ">$root/boards/record.txt");



flock(PRINTBOARD,2);



print PRINTBOARD @print_again;



close(PRINTBOARD);





@postfile = reverse(@postfile);



close(OPBOARD);



$s = 0;



foreach $p(@postfile){




print $p;



}



print "<hr>\n";



require "$root/inc/check_pm.inc";

require "$root/inc/print_footer.inc";



exit;

