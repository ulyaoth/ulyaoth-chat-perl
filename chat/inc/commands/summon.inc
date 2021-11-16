#!/usr/bin/perl



if ($command eq '/summon' && $level >= 1 && $deopped ne 1){



@summon = split(/\s+/, $DATA{'msg'});



@summon[1]=substr(@summon[1],0,14);



if(@summon[1] eq ''){



$errors = " Syntax: /summon [nick].";



return $errors;



exit;





}







if(!-e "$root/online/users/@summon[1]"){  





$errors =  " Error, user <b>@summon[1]</b> not found."; 

                  





return $errors;



exit;





}



if(@summon[1] eq $DATA{'n'}){  





$errors = " Syntax: /summon [nick].";  



 return $errors;



exit;





}

if($room eq "CyberSex"){  



$errors = " Error, you are not allowed to /summon while you are in CyberSex room.";  



 return $errors;



exit;





}








dbmopen(%USER,"$root/online/users/@summon[1]",0777);


if($USER{'null'}){



$errors =  " Error , user <b>@summon[1]</b> is not allowing summons."; 



dbmclose(%USER);           

 

return $errors;



exit;



}





if($room eq $USER{'room'}){





$errors =  " Error , the user <b>@summon[1]</b> you are attepting to summon is already in room <b>$room</b>."; 

                  

dbmclose(%USER);



return $errors;



exit;



}



$USER{'summoner'} = $DATA{'n'};



$USER{'summonroom'} = $room;



dbmclose(%USER);





$errors = " Attempting to summon <b>@summon[1]</b> to room <b>$room</b>.";  



return $errors;



exit;





}elsif($command eq '/summon' && $level >= 1 && $deopped == 1){





$errors = " Sorry, you are not allowed to use this command.";



 return $errors;



exit;         



}elsif($command eq '/summon' && $level < 1){





$errors = " Command $command not recognized, please use /help for a list of commands.";



return $errors;



exit;        

}







