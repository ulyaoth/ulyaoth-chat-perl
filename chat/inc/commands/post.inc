#!/usr/bin/perl



foreach $pmimg(@imegs){

$DATA{'msg'} =~ s/$pmimg\b/<img src=\"\/img$pmimg.gif\">/g;

}



if ($level >= 1){ 


@post = split(/\s+/,$DATA{'msg'});


foreach $key(@post){

if($key =~ /<img/){

$z++;
}
}


if($z > 5){

$errors = " Error, you can not post more than 5 images per message.";

return $errors;

exit;


}


$poost = $DATA{'msg'};

$poost =~ s/^\/post//;





if(!@post[1]){



$errors = " Syntax: /post [message].";



return $errors;



exit;



}



for (0..9) { $postid .= pack("C",65+int(rand(25.9999))); }



open(OPSBOARD,">>$root/boards/opsboard.txt");



flock(OPSBOARD,2);



print OPSBOARD "$postid \|\"\'\|<!-- $postid --> <b>$realnick</b><font size=\"1\" color=\"$iback\">i</font> ($ip) $fulltime<br> $scolor$poost$ecolor<p>\n";



close(OPSBOARD);



$errors = " Message posted $fulltime: <font size=\"1\" color=\"$iback\">i</font>$poost";



return $errors;



exit;





}







if ($level < 1){

                

        $errors = " Error, command $command not recognized, please use /help for a list of commands.";





 return $errors;



exit;



       }

        