#!/usr/bin/perl



if($command eq '/opslist' && $level < $staff_rank){



$errors = " Error, command $command not recognized, please use /help for a list of commands.";

        

return $errors;



exit;



}


print "Content-type: text/html\n\n";


require "$root/inc/print_header.inc";





print "<hr>";


 $c = 0;


       opendir(OPSDIR,"$root/ops/ops");

flock(OPSDIR,2);

        @opsdir = readdir(OPSDIR);

        closedir(OPSDIR);



        foreach $stuff(sort (@opsdir)){



        if ($stuff ne "." && $stuff ne ".."){



                $stuff =~ s/.db//ig;



         dbmopen(%OPER,"$root/ops/ops/$stuff",0777);



        print "*** Acc: <b>$stuff</b>. Level: $OPER{'level'}. Id: $OPER{'id'}. Started: $OPER{'ops_began'}. End: $OPER{'ops_end'}.<br>\n";

        

dbmclose(%OPER);



$c++;

        }

}

                

print "TOTAL: <b>$c</b> operators in database.<br>\n";

 

   require "$root/inc/print_footer.inc";



     exit;