#!/usr/bin/perl


if($level < 1 && $level ne "granted"){
                
        $errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

       }

foreach $pmimg(@imegs){

$DATA{'msg'} =~ s/$pmimg\b/<img src=\"\/img$pmimg.gif\">/g;

}



$text_action = $DATA{'msg'};

$text_action =~ s/^\/\/smile//;

$text_action =~ s/^\s+//;

@action = split(/\s+/, $DATA{'msg'});

$text_action =~ s/^@action[1]//;

$text_action =~ s/^\s+//;

foreach $key(@action){

if($key =~ /<img/){

$z++;
}
}


if($z > 5){

$errors = " Error, you can not post more than 5 images per message.";

return $errors;

exit;


}


if(!@action[1]){

open(ACT,">>$root/online/rooms/$room.txt");

flock(ACT,2);

print ACT "$scolor* <b>$DATA{'n'}</b> <b>smiles at everyone in the room <img src=\"\/img\/smile.gif\"></b>$ecolor<br>\n";

close(ACT);

$bypass = 1;

return $bypass;

exit;



}


if(!-e "$root/online/users/@action[1]"){

$errors = " Error, user <b>@action[1]</b> not found.";

return $errors;

exit;


}

if(!$text_action){

$text_action = "gives a big bright smile to";
}


@mes = split(/\s+/,$text_action);

foreach $key(@mes){

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


open(ACT,">>$root/online/rooms/$room.txt");

flock(ACT,2);

print ACT "$scolor* <b><font color=\"red\">$DATA{'n'}</font></b> <b>@mes <font color=\"red\">@action[1]</font> <img src=\"\/img\/smile.gif\"> *</b>$ecolor<br>\n";

close(ACT);


$bypass = 1;

return $bypass;

exit;



        