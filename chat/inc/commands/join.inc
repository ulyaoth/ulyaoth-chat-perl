#!/usr/bin/perl





@location = split(/\s+/, $DATA{'msg'});





@location[1] =~ s/[^\w]//g;



@location[1]=substr(@location[1],0,14);





unless(@location[1]){



$errors = " Syntax: /join [location].";



return $errors;



exit;



}





if(length(@location[1]) < 2){



$errors = " Error, room names must be 2-14 characters long. Syntax: /join [location].";



return $errors;



exit;



}





if($room =~ /@location[1]/i && length(@location[1]) == length($room)){



$errors = " Error, already in location $room.";



return $errors;



exit;



}





foreach $bb(@rooms){



if($bb =~ /@location[1]/i && length(@location[1]) == length($bb)){



$public_join = 1;



@location[1] = $bb;

}



}







if($public_join != 1 && !-e "$root/online/rooms/@location[1].txt" && $level < 1){



$errors = " Error, only Operators can create a new rooms.";



return $errors;



exit;



}





if(-e "$root/online/locked/@location[1].txt"){



open(LOCKED,"$root/online/locked/@location[1].txt");



$locked = <LOCKED>;



close(LOCKED);



@locked = split(/\|\"\'\|/, $locked);



if(@locked[0] eq $DATA{'n'}){



}else{



$errors = " Error, location <b>@location[1]</b> has been locked by <b>@locked[0]<font size=\"1\" color=\"$iback\">i</font> (@locked[2])</b> Time:<b> @locked[3]</b>.";



return $errors;

exit;

}



}





dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);



$oldroom = $USER{'room'};



$ipaddr = $USER{'ip'};



$USER{'room'} = @location[1];



dbmclose(%USER);





open(OLD,">>$root/online/rooms/$oldroom.txt");



flock(OLD,2);

print OLD "<!--servermsg--> *** <B>$DATA{'n'}</B><font size=\"1\" color=\"$iback\">i</font> ($ipaddr) / has left location <B>$oldroom</B>.<br>\n";



close(OLD);



open(NEW,">>$root/online/rooms/@location[1].txt");



flock(NEW,2);



$DATA{'room'} = @location[1];



$room = @location[1];



if($DATA{'room'} eq "Doorstep"){








     $welcome = "$DATA{'n'} trips over the Doorstep!";



}elsif($DATA{'room'} eq "Hot_Tub"){



     $welcome = "$DATA{'n'} does a cannonball into the Hot_Tub!";



}elsif($DATA{'room'} eq "Forest"){



     $welcome = "$DATA{'n'} is chained to a tree in the Forest!";



}elsif($DATA{'room'} eq "20plus"){



     $welcome = "$DATA{'n'} wants to talk to someone their own age!";



}elsif($DATA{'room'} eq "30plus"){



     $welcome = "$DATA{'n'} wants to talk to someone their own age!";



}elsif($DATA{'room'} eq "40plus"){



     $welcome = "$DATA{'n'} wants to talk to someone their own age!";



}elsif($DATA{'room'} eq "Australia"){



     $welcome = "G'Day Mate!";



}elsif($DATA{'room'} eq "Bar"){



     $welcome = "$DATA{'n'} walks in hoping to get drunk!";



}elsif($DATA{'room'} eq "Canada"){



     $welcome = "Welcome, eh!";

}elsif($DATA{'room'} eq "Woods"){



     $welcome = "$DATA{'n'} wanders into the Woods!!!";



}elsif($DATA{'room'} eq "Courtyard"){



     $welcome = "$DATA{'n'} strolls into the Courtyard!";



}elsif($DATA{'room'} eq "CyberSex"){



     $welcome = "$DATA{'n'} is looking for some cyber-luvin!";



}elsif($DATA{'room'} eq "New_Users"){



     $welcome = "$DATA{'n'} is new here and would like to make some friends!";



}elsif($DATA{'room'} eq "Teens"){



     $welcome = "$DATA{'n'} wants to talk to someone their own age!";



}elsif($DATA{'room'} eq "UK"){



     $welcome = "Welcome to the UK!";



}elsif($DATA{'room'} eq "USA"){



     $welcome = "Welcome to the USA!";



}elsif($DATA{'room'} eq "Mexico"){



     $welcome = "Recepción!";



}elsif($DATA{'room'} eq "Quebec"){



     $welcome = "Bienvenue!";



}elsif($DATA{'room'} eq "Germany"){



     $welcome = "Willkommen!";



}elsif($DATA{'room'} eq "Arabia"){



     $welcome = "Salam!";



}elsif($DATA{'room'} eq "Belgium"){



     $welcome = "Welkom!";



}elsif($DATA{'room'} eq "India"){



     $welcome = "Welcome to India!";



}elsif($DATA{'room'} eq "Indonesia"){



     $welcome = "Welcome to Indonesia!";



}elsif($DATA{'room'} eq "Malaysia"){



     $welcome = "Selamat Datang!";



}elsif($DATA{'room'} eq "China"){



     $welcome = "Ni How!";



}elsif($DATA{'room'} eq "Hong_Kong"){



     $welcome = "Nei Ho!";



}elsif($DATA{'room'} eq "Philipines"){



     $welcome = "Mabuhay!";



}elsif($DATA{'room'} eq "Turkey"){



     $welcome = "Selam!";





}elsif($DATA{'room'} eq "Holland"){



     $welcome = "Welkom!";



}else{





$welcome = "Welcome!!!";



}





print NEW "<!--servermsg--> *** <B>$DATA{'n'}</B><font size=\"1\" color=\"$iback\">i</font> ($ipaddr) <b>$DATA{'room'}</b> / $welcome<br>\n";


if($DATA{'room'} eq "CyberSex"){

open(PRIV,">>$root/online/pm/$DATA{'n'}.txt");

flock(PRIV,2);


print PRIV "<!-- $time --> <b>WARNING: Must be at least 18 years old (or the legal age in your country) to enter this room.  If you are not legal age, please leave this room immediately. By entering this room, you agree that you are of legal age in your country.  You agree to waive all rights to direct or indirect legal action against Bombastik Internet, hereafter referred to as Bombastik.  Bombastik is not responsible in any way for user generated content on our sites. Bombastik is not directly or indirectly responsible for the effects of site content or denial of access to services.</b><br>\n";


close(PRIV);



}





if($public_join != 1 && $level >= 1){



print NEW "<!--servermsg--> *** Location <b>$DATA{'room'}</b> has been locked by <b>$DATA{'n'}</b>.<br>\n";



open(LOCK,">$root/online/locked/$DATA{'room'}.txt");



print LOCK "$DATA{'n'}\|\"\'\|$realnick\|\"\'\|$ip\|\"\'\|$fulltime";



close(LOCK);



}



close(NEW);



if($frames eq 'yes'){

$mkframe = 1;



return $mkframe;



}



return $room;

exit;