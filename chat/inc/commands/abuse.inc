#!/usr/bin/perl




if ($command eq '/abuse' && $level < 1){
                
        $errors = " Error, command $command not recognized, please use /help for a list of commands.";


 return $errors;

exit;

       }



@abuse = split(/\s+/,$DATA{'msg'});

unless(@abuse[1]){

$errors = " Syntax: /abuse [nick].";

return $errors;

exit;

}


if(!-e "$root/online/users/@abuse[1]"){
     close(NOTANOP);
     
$errors = " Error, Op <b>@abuse[1]</b> not found.";

return $errors;

exit;

            }



dbmopen(%USER,"$root/online/users/@abuse[1]",0777);

$abuselevel = $USER{'level'};

$a_real_nick = $USER{'realnick'};

$a_room = $USER{'room'};

dbmclose(%USER);



if($abuselevel < 1){

$errors = " Error, <b>@abuse[1]</b> is not an Op.";

return $errors;

exit;

}



for (0..15) { $nr .= pack("C",97+int(rand(25.9999))); }

open(ABUSENR,">>$root/abuse/$time_file.txt");

print ABUSENR "$nr\|\"\'\|<b>*** Ops $DATA{'n'} ($realnick) ($room) against @abuse[1] ($a_real_nick) ($a_room)</b> time: $fulltime.\n";

close(ABUSENR);



open(ABUSE,">$root/abuse/reports/$nr.txt");

print ABUSE "<center>Room <b>$a_room</b> Time: $fulltime</center><hr>\n";


open(FROOM, "$root/online/rooms/$a_room.txt");

flock(FROOM,2);

@ab = <FROOM>;

close(FROOM);


foreach $line(@ab){

print ABUSE $line;

}

print ABUSE "<p><hr>\n<center>Room <b>$room</b> Time: $fulltime</center><hr>\n";


open(EROOM, "$root/online/rooms/$room.txt");

flock(EROOM,2);

@ac = <EROOM>;

close(EROOM);

foreach $y(@ac){

print ABUSE $y;


}


print ABUSE "<hr><p><center>Record of private messages.</center><p>\n";


print ABUSE "<hr><center>User: <b>$DATA{'n'} ($realnick)</b>. Buffer saved. Time: $fulltime.</center>\n";


open(APM,"$root/online/pm/$DATA{'n'}.txt");

flock(APM,2);

@abuserx = <APM>;

close(APM);

foreach $line(@abuserx){

print ABUSE $line;

}


print ABUSE "<br><b>END OF BUFFER</b><p>\n<hr><center>User: <b>@abuse[1] ($a_real_nick)</b>. Buffer saved. Time: $fulltime</center>\n";

open(PIM,"$root/online/pm/@abuse[1].txt");

flock(PIM,2);

@pim = <PIM>;

close(PIM);

foreach $j(@pim){

print ABUSE $j;

}


print ABUSE "<p><b>END OF ABUSE REPORT</b><p>";

close(ABUSE);





$errors = " Abuse report submited. Please use /comm command to post a message on comm board and help us with your report.";

return $errors;

exit;


        