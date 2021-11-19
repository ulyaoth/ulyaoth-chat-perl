#!/usr/bin/perl


if($level < 1){



$errors = " Command $command not recognized, please use /help for a list of commands.";

        

return $errors;



exit;

}



if($ip =~ '#'){



dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);



($ip1,$ip2,$ip3)=split(/\./,$ENV{'REMOTE_ADDR'});



$ip = "$ip1.$ip2.$ip3";



$USER{'ip'} = "$ip"; 



dbmclose(%USER);



$errors = "Ops flags hidden, <b>$DATA{'n'}</b><font size=\"1\" color=\"$iback\">i</font> ($ip).";



return $errors;





}else{

dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);


if($level < $comm_rank){

$USER{'ip'} = "#$ip#"; 

}else{

$USER{'ip'} = "##$ip##"; 

}


dbmclose(%USER);



open(FLAGS, ">>$root/online/rooms/$room.txt");



flock(FLAGS,2);

if($level < $comm_rank){

print FLAGS "<!--servermsg--> *** Operator <b>$DATA{'n'}</b><font size=\"1\" color=\"$iback\">i</font> (#$ip#).<br>\n";

 }else{

print FLAGS "<!--servermsg--> *** Operator <b>$DATA{'n'}</b><font size=\"1\" color=\"$iback\">i</font> (##$ip##).<br>\n";


}

close(FLAGS);


if($level < $comm_rank){

$errors = "Ops flags restored, <b>$DATA{'n'}</b><font size=\"1\" color=\"$iback\">i</font> (#$ip#).";

}else{

$errors = "Ops flags restored, <b>$DATA{'n'}</b><font size=\"1\" color=\"$iback\">i</font> (##$ip##).";

}


return $errors;



}