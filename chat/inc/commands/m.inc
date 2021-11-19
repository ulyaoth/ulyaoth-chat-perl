#!/usr/bin/perl


foreach $pmimg(@imegs){

$DATA{'msg'} =~ s/$pmimg\b/<img src=\"\/img$pmimg.gif\">/g;

}



@msg = split(/\s+/,$DATA{'msg'});

@msg[1] =~ s/[^\w\Á\È\Ê\Ë\Ì\Í\Î\Ï\ä\Ñ\Ó\Ô\Õ\Ö\Ø\Ù\Ú\Û\Ý\Þ\ß\á\ã\ä\æ\í\À\Â\Ã\Ä\Å\Æ\Ç\É\Ð\Ö\Ò\à\å\æ\ç\è\é\ê\ë\ì\í\î\ï]//g;

@msg[1]=substr(@msg[1],0,15);

$z = 0;

foreach $key(@msg){

if($key =~ /<img/){

$z++;
}
}


if($z > 5){

$errors = " Error, you can not post more than 5 images per message.";

return $errors;

exit;


}


unless(@msg[2]){



$errors = " Syntax: /msg [nick] [message].";



return $errors;



exit;



}





if(@msg[1] eq $DATA{'n'}){



$errors = " Not allowed, or duplicate.";

         return $errors;



exit;

}





if(!-e "$root/online/users/@msg[1].db"){



$errors =  " Error, user <b>@msg[1]</b><font size=\"1\" color=\"$iback\">i</font> not found.";



   return $errors;



exit;                

            

}



open(IG,"$root/online/ig/@msg[1].txt");



@ig = <IG>;



close(IG);



foreach $line(@ig){



chop($line);



if($line eq $DATA{'n'}){



$errors = " Sorry, user <b>@msg[1]</b><font size=\"1\" color=\"$iback\">i</font> is ignoring your messages.";



return $errors;



exit;



}}




dbmopen(%LAST,"$root/online/users/$DATA{'n'}.db",0777);





$lastpm = $LAST{'lastpm'};



dbmclose(%LAST);



if($lastpm eq $DATA{'msg'}){



$errors = " Not allowed, or duplicate.";



return $errors;



exit;



}



dbmopen(%USER,"$root/online/users/@msg[1].db",0777);


if($USER{'ignore_all'}){



$errors = " Sorry, user <b>@msg[1]</b><font size=\"1\" color=\"$iback\">i</font> is ignoring your messages.";



dbmclose(%USER);



return $errors;



exit;



}

$users_mode = $USER{'mode'};

$showie_idle = $time - $USER{'idle'};

if($showie_idle > 50 && !$users_mode){

$show_idle_time = "\($showie_idle sec\)";

}


$USER{'auto_list'} =~ s/\s+//ig;

if($USER{'auto_list'} =~ /!$realnick/){

$auto = 1;

}




if(!$auto && $USER{'auto_replay'}){

$USER{'auto_list'} = "$USER{'auto_list'}\!$realnick";

open(PR,">>$root/online/pm/$DATA{'n'}.txt");

flock(PR,2);

print PR "<!-- $time --> <A HREF=\"javascript:m('@msg[1]')\"><B>\*@msg[1]\*</b></a><font size=\"1\" color=\"$iback\">i</font> ($USER{'ip'}) $USER{'auto_replay'}<br>\n";

close(PR);

}

undef $auto;

dbmclose(%USER);



if($users_mode){



$away = "Message sent, User <b>@msg[1]</b><font size=\"1\" color=\"$iback\">i</font> is AWAY!<br>\n";


}




dbmopen(%L,"$root/online/users/$DATA{'n'}.db",0777);

$L{'lastpm'} = $DATA{'msg'};




dbmclose(%L);

open(PRIVE,">>$root/online/pm/@msg[1].txt");


flock(PRIVE,2);

print PRIVE "<!-- $time --> $scolor<A HREF=\"javascript:m('$DATA{'n'}')\"><B>\*$DATA{'n'}\*</b></a><font size=\"1\" color=\"$iback\">i</font> ($ip) ";



$count = 0;



push(@sndmsg,"$away-> $scolor<b>\*@msg[1]\*<font size=\"1\" color=\"$iback\">i</font> $show_idle_time</b>");

 

           foreach $key (@msg){

                   if ($count ne 0 && $count ne 1){

                            print PRIVE "@msg[$count] ";

                            push(@sndmsg,"@msg[$count] ");

                    }

                    $count++;

            }

            print PRIVE " $ecolor<br>\n";

            push(@sndmsg,"$ecolor<br>");

            close(PRIVE);

          

                        $bypass = 1;

return @sndmsg;

return $bypass;

exit;