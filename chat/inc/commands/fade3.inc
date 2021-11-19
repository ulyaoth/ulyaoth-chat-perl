#!/usr/bin/perl

if ($command eq '//fade3' && $level >= 1){



$DATA{'msg'} =~ s/\&lt\;//g;

$DATA{'msg'} =~ s/\&gt\;//g;



$DATA{'msg'}=substr($DATA{'msg'},0,70);


@message = split(/\s+/,$DATA{'msg'});

$message[1] =~ s/[^\w]//g;

$message[2] =~ s/[^\w]//g;

$message[3] =~ s/[^\w]//g;


if(length($message[1]) > 6){

$message[1]=substr($message[1],0,6);

}

if(length($message[2]) > 6){

$message[2]=substr($message[2],0,6);

}


if(length($message[3]) > 6){

$message[3]=substr($message[3],0,6);

}



if(length($message[1]) < 6){


$errors = " Syntax: //fade [hex-1] [hex-2] [hex-3] [message].\n";

return $errors;

exit;


}
if(length($message[2]) < 6){


$errors = " Syntax: //fade [hex-1] [hex-2] [hex-3] [message].\n";

return $errors;

exit;


}


if(length($message[3]) < 6){


$errors = " Syntax: //fade [hex-1] [hex-2] [hex-3] [message].\n";

return $errors;

exit;


}











if (($message[1] ne "") &&
    ($message[2] ne "") &&
    ($message[3] ne "") &&
    ($message[4] ne "")){
$DATA{'msg'} =~ s/$message[0]//;
$DATA{'msg'} =~ s/$message[1]//;
$DATA{'msg'} =~ s/$message[2]//;
$DATA{'msg'} =~ s/$message[3]//;
$|=1;
my $color1 = $message[1];

my $color2 = $message[2];
my $color3 = $message[3];
my $message = "$DATA{'msg'}";

my $strLen = length($message);
my $strLen1 = $strLen/2;
# get the individual colors:

my ($r1,$g1,$b1)= (substr($color1,0,2), substr($color1,2,2), 
substr($color1,4,2));

#convert
my $Rinit=eval("0x$r1");
my $Ginit=eval("0x$g1");
my $Binit=eval("0x$b1");

########## COLOR 2 ################
# get individual colors of $color2
my ($r2,$g2,$b2)= (substr($color2,0,2), substr($color2,2,2), 
substr($color2,4,2));

#convert
my $Rfin=eval("0x$r2");
my $Gfin=eval("0x$g2");
my $Bfin=eval("0x$b2");

# ######## COLOR 3 ################
# get individual colors of $color3
my ($r3,$g3,$b3)= (substr($color3,0,2), substr($color3,2,2), 
substr($color3,4,2));

#convert
$Rlst=eval("0x$r3");
$Glst=eval("0x$g3");
$Blst=eval("0x$b3");


#Find the incriment
$Rincr=($Rfin-$Rinit)/$strLen1;
$Gincr=($Gfin-$Ginit)/$strLen1;
$Bincr=($Bfin-$Binit)/$strLen1;

$RincrL=($Rlst-$Rfin)/$strLen1;
$GincrL=($Glst-$Gfin)/$strLen1;
$BincrL=($Blst-$Bfin)/$strLen1;


#Addthe colors
for($i=0;$i<$strLen1;$i++)
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
for(my $j=$i;$j<$strLen;$j++)
{
    $t++;

    my $currRL=$Rfin+($RincrL*$t);
    my $currGL=$Gfin+($GincrL*$t);
    my $currBL=$Bfin+($BincrL*$t);

        my $oneChar=substr($message,$j,1);

    #change back to HTML colors
    my $r=sprintf "%x", $currRL;
    my $g=sprintf "%x", $currGL;
    my $b=sprintf "%x", $currBL;

    #make sure it fits the HTML color format here
    while(length($r)<2) {$r="0$r";}
    while(length($g)<2) {$g="0$g";}
    while(length($b)<2) {$b="0$b";}
    $themsg="$themsg<font color=\'$r$g$b\'>$oneChar</font>";

}

        open(FADEROOM,">>$root/online/rooms/$room.txt");

flock(FADEROOM,2);

print FADEROOM "<font color=\"\#000000\">\[</font><A style=\"text-decoration: none\; color: $nickcolor\; font-family: $nicktype\" href=\"javascript:m('$DATA{'n'}')\"><b>$DATA{'n'}</b></a><font color=\"\#000000\">\]</font><font size=\"1\" color=\"$iback\">i</font> <b>$FACECOLOR $themsg</b><br>\n";

close(FADEROOM);

$bypass = 1;

return $bypass;

exit;


}else{

     $errors= " Syntax: //fade3 [hex-1] [hex-2] [hex-3] [message].\n";

return $errors;

exit;  

 

}
  }    

if($command eq '//fade3' && $level < 1){

&roomidle;
&idle;


$errors = " Command $command not recognized, please use /help for a list of commands.";
        
return $errors;

exit;


}