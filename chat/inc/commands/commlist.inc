#!/usr/bin/perl



if($command eq '/commlist' && $level < $comm_rank){



$errors = " Error, command $command not recognized, please use /help for a list of commands.";

        

return $errors;



exit;



}


print "Content-type: text/html\n\n";


require "$root/inc/print_header.inc";





print "<hr>";


 $c = 0;


       opendir(OPSDIR,"$root/ops/ops/");



        @opsdir = readdir(OPSDIR);

        closedir(OPSDIR);



        foreach $stuff (sort @opsdir){



        if ($stuff ne '.' && $stuff ne '..'){



                $stuff =~ s/.db//;



         dbmopen(%OPER,"$root/ops/ops/$stuff",0777);


if($OPER{'level'} >= $comm_rank){

        print "<b>*** Operator $stuff. Level: $OPER{'level'}. Id: $OPER{'id'}.</b><br>\n";

$c++; 
       }

dbmclose(%OPER);





        }}

                

print "TOTAL: <b>$c</b>.<br>\n";

 

   require "$root/inc/print_footer.inc";



     exit;