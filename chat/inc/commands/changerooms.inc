#!/usr/bin/perl







foreach $key(@rooms){



if($DATA{'room'} eq $key){



$r = 1;



}}



if($r ne 1){



if($level >= 1){



$errors = " Error, not allowed. Please use /join command to create a new room.";



return $errors;



exit;



}else{



$errors = " Error, not allowed.";



return $errors;



exit;



}

}





dbmopen(%USER,"$root/online/users/$DATA{'n'}",0777);



$ro = $USER{'room'};



$USER{'room'} = $DATA{'room'};



dbmclose(%USER);



open(OLDROOM,">>$root/online/rooms/$ro.txt");



flock(OLDROOM,2);



print OLDROOM "<!--servermsg--> *** <B>$DATA{'n'}</B><font size=\"1\" color=\"$iback\">i</font> ($ip) / has left location <B>$ro</B>.<br>\n";



close(OLDROOM);



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


}elsif($DATA{'room'} eq "Woods"){



     $welcome = "$DATA{'n'} wanders into the Woods!!!";




}elsif($DATA{'room'} eq "Canada"){



     $welcome = "Welcome, eh!";



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



open(NEWROOM,">>$root/online/rooms/$DATA{'room'}.txt");



flock(NEWROOM,2);



print NEWROOM "<!--servermsg--> *** <B>$DATA{'n'}</B><font size=\"1\" color=\"$iback\">i</font> ($ip) <b>$DATA{'room'}</b> / $welcome<br>\n";



close(NEWROOM);


if($DATA{'room'} eq "CyberSex"){

open(PRIV,">>$root/online/pm/$DATA{'n'}.txt");

flock(PRIV,2);


print PRIV "<!-- $time --> <b>WARNING: Must be at least 18 years old (or the legal age in your country) to enter this room.  If you are not legal age, please leave this room immediately. By entering this room, you agree that you are of legal age in your country.  You agree to waive all rights to direct or indirect legal action against Bombastik Internet, hereafter referred to as Bombastik.  Bombastik is not responsible in any way for user generated content on our sites. Bombastik is not directly or indirectly responsible for the effects of site content or denial of access to services.</b><br>\n";


close(PRIV);



}








$room = $DATA{'room'};



return $room;



return true;













