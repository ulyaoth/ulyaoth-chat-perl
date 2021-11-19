#!/usr/bin/perl



if($command eq '/suspendlist' && $level < $staff_rank){



$errors = " Error, command $command not recognized, please use /help for a list of commands.";

        

return $errors;



exit;



}


print "Content-type: text/html\n\n";


require "$root/inc/print_header.inc";


require "$root/inc/print_room.inc";


print "<hr>";


 $c = 0;


       opendir(DIR,"$root/suspend/");



        @deopdir = readdir(DIR);

        closedir(DIR);



        foreach $stuff (sort @deopdir){



        if ($stuff ne '.' && $stuff ne '..'){



                $stuff =~ s/.db//;



         dbmopen(%DEOPPED,"$root/suspend/$stuff",0777);



        print "$DEOPPED{'suspend'}<br>";

        

dbmclose(%DEOPPED);



$c++;

        }}

                

print "TOTAL: <b>$c</b>.<br>\n";

 

   require "$root/inc/print_footer.inc";



     exit;