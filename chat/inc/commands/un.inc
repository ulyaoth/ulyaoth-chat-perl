#!/usr/bin/perl





if ($level < 1 && $level ne "granted"){

                

        $errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;



       }


foreach $pmimg(@imegs){

$DATA{'msg'} =~ s/$pmimg\b/<img src=\"\/img$pmimg.gif\">/g;

}





$blue = $DATA{'msg'};



$blue =~ s/^\/\/un//;



@ablue = split(/\s+/, $DATA{'msg'});



if(!@ablue[1]){



$errors = " Syntax: //un [message].";



return $errors;



exit;   



}



@blue_message = split(/\s+/,$blue);


foreach $key(@blue_message){

if($key =~ /<img/){

$z++;
}
}


if($z > 5){

$errors = " Error, you can not post more than 5 images per message.";

return $errors;

exit;


}


foreach $key(@blue_message){



if($key =~ /^\/\//){



$a_key = $key;



$a_key =~ s/^\/\///ig;



$one_key = substr($a_key,0,6);



if(length($key) > 8 && $one_key !~ /[\W]/){



$a_key = substr($a_key,6,length($a_key));



$key = "<font color=\"$one_key\">$a_key</font>";



}



}

}





open(RED,">>$root/online/rooms/$room.txt");



flock(RED,2);







print RED "<font color=\"\#000000\">\[</font><A style=\"text-decoration: none\; color: $nickcolor\; font-family: $nicktype\" href=\"javascript:m('$DATA{'n'}')\"><b>$DATA{'n'}</b></a><font color=\"\#000000\">\]</font><font size=\"1\" color=\"$iback\">i</font>$scolor <u>@blue_message</u>$ecolor<br>\n";





close(RED);





$bypass = 1;



return $bypass;



exit;