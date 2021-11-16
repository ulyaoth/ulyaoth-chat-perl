#!/usr/bin/perl







if($command eq '/unban' && $level < 1){



$errors = " Error, command $command not recognized, please use /help for a list of commands.";

        

return $errors;



exit;



}



if($command eq '/unban' && $deopped == 1){





$errors = " Error , you are not allowed to use this command.";

        

return $errors;



exit;





}











@unban = split(/\s+/, $DATA{'msg'});

 

if(@unban[1] eq ''){



print "Content-type: text/html\n\n";



require "$root/inc/print_header.inc";



require "$root/inc/print_room.inc";





print "<hr>";



 $c = 0;



       opendir(BANDIR,"$root/online/banned/");



        @bandir = readdir(BANDIR);

        closedir(BANDIR);



        foreach $stuff (sort @bandir){



        if ($stuff ne '.' && $stuff ne '..'){



                $stuff =~ s/.db//;



         dbmopen(%BANNED,"$root/online/banned/$stuff",0777);



        print $BANNED{'ban'};

        

dbmclose(%BANNED);



$c++;

        }}

                



print "TOTAL: <b>$c</b> ban(s).<br>\n";

 









   require "$root/inc/print_footer.inc";









     exit;



}





if(!-e "$root/online/banned/@unban[1]"){



$errors = " Error , ban <b>@unban[1]</b> does not exist.";



        close(FR);



return $errors;



exit;



}





dbmopen(%BANNED,"$root/online/banned/@unban[1]",0777);



$unban = $BANNED{'owner'};



dbmclose(%BANNED);



if ($unban ne $realnick && $level < $comm_rank){



$errors = " Error , you are not owner of this ban.";



return $errors;



exit;



}



open(UNBANROOM,">>$root/online/rooms/$room.txt");



flock(UNBANROOM,2);



print UNBANROOM "*** Ban <b>@unban[1]</b> removed by <b>$DATA{'n'}</b><br>\n";



close(UNBANROOM);



unlink("$root/online/banned/@unban[1]");





$msg_action = "<!-- $time -->*** UNBAN: Ban <b>@unban[1]</b> removed by <B>$DATA{'n'}<font size=\"1\" color=\"$iback\">i</font> $online_time</b> <font size=\"1\" color=\"$iback\">i</font>($realnick) ($room).<br>\n";



require "$root/inc/msg_action.inc";



undef $msg_action;





$errors = " Ban <b>@unban[1]</b> removed.";



return $errors;



exit;









