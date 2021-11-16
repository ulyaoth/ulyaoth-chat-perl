#!/usr/bin/perl

if ($command eq '//fade' && $level >= 1){


$DATA{'msg'} =~ s/\&lt\;//g;

$DATA{'msg'} =~ s/\&gt\;//g;

$DATA{'msg'}=substr($DATA{'msg'},0,60);

@message = split(/\s+/,$DATA{'msg'});

$message[1] =~ s/[^\w]//g;

$message[2] =~ s/[^\w]//g;


if(length($message[1]) > 6){

$message[1]=substr($message[1],0,6);

}


if(length($message[2]) > 6){

$message[2]=substr($message[2],0,6);

}



if(length($message[1]) < 6){


$errors = " Syntax: //fade [hex-1] [hex-2] [message].\n";

return $errors;

exit;


}

if(length($message[2]) < 6){

$errors = " Syntax: //fade [hex-1] [hex-2] [message].\n";

return $errors;

exit;


}





if (($message[1] ne "") &&
    ($message[2] ne "") &&
    ($message[3] ne "")){

$DATA{'msg'} =~ s/$message[0]//;
$DATA{'msg'} =~ s/$message[1]//;
$DATA{'msg'} =~ s/$message[2]//;

$|=1;
my $color1 = $message[1];
my $color2 = $message[2];
my $message = "$DATA{'msg'}";

my $strLen = length($message);

# get the individual colors:

my ($r1,$g1,$b1)= (substr($color1,0,2), substr($color1,2,2), 
substr($color1,4,2));

#convert
my $Rinit=eval("0x$r1");
my $Ginit=eval("0x$g1");
my $Binit=eval("0x$b1");

# get individual colors of $color2
my ($r2,$g2,$b2)= (substr($color2,0,2), substr($color2,2,2), 
substr($color2,4,2));

#convert
my $Rfin=eval("0x$r2");
my $Gfin=eval("0x$g2");
my $Bfin=eval("0x$b2");

#Find the incramint
my $Rincr=($Rfin-$Rinit)/$strLen;
my $Gincr=($Gfin-$Ginit)/$strLen;
my $Bincr=($Bfin-$Binit)/$strLen;



#Addthe colors
for(my $i=0;$i<$strLen;$i++)
{

    my $currR=$Rinit+($Rincr*$i);
    my $currG=$Ginit+($Gincr*$i);
    my $currB=$Binit+($Bincr*$i);

	my $oneChar=substr($message,$i,1);

    #change back to HTML colors
    my $r=sprintf "%x", $currR;
    my $g=sprintf "%x", $currG;
    my $b=sprintf "%x", $currB;

    #make sure it fits the HTML color format here
    while(length($r)<2) {$r="0$r";}
    while(length($g)<2) {$g="0$g";}
    while(length($b)<2) {$b="0$b";}
    $themsg="$themsg<font color=\'$r$g$b\'>$oneChar</font>";

}
	open(TIME,">>$root/online/rooms/$room.txt");

flock(TIME,2);

print TIME "<font color=\"\#000000\">\[</font><A style=\"text-decoration: none\; color: $nickcolor\; font-family: $nicktype\" href=\"javascript:m('$DATA{'n'}')\"><b>$DATA{'n'}</b></a><font color=\"\#000000\">\]</font><font size=\"1\" color=\"$iback\">i</font> <b>$FACECOLOR $themsg</b><br>\n";

close(TIME);

$bypass = 1;

return $bypass;

exit;

}else{
     
     $errors = " Syntax: //fade [hex-1] [hex-2] [message].\n";

return $errors;

exit;
}

}

if($command eq '//fade' && $level < 1){


$errors = " Command $command not recognized, please use /help for a list of commands.";
        
return $errors;

exit;


}






