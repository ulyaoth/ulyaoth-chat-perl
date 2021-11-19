#!/usr/bin/perl



if ($level <= 1){

$errors = "Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

}



@ip = split(/\s+/,$DATA{'msg'});


@ip[1] =~ s/[^\w-\.]//g;


if(!@ip[1] or length(@ip[1]) > 15 or @ip[1] =~ /admin/i && $level < $staff_rank or @ip[1] =~ /staffadmin/i && $level < $staff_rank or @ip[1] =~ /comm/i && $level < $comm_rank){

$errors = " Syntax: /ip [text from 1 to 15 characters].";

return $errors;

exit;

}


if($level > 1 && $level < $comm_rank && $level < $staff_rank){

$temp_ip = "#@ip[1]#";

$who_op = "Operator";

}elsif($level > 1 && $level >= $comm_rank && $level < $staff_rank){

$temp_ip = "##@ip[1]##";

$who_op = "Committee";

}elsif($level > 1 && $level > $comm_rank && $level >= $staff_rank){

$temp_ip = "##<font color=red>@ip[1]</font>##";

$who_op = "Admin";



}





dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

$USER{'ip'} = $temp_ip;  

dbmclose(%USER);

open(FLAG, ">>$root/online/rooms/$room.txt");

flock(FLAG,2);

print FLAG "<!--servermsg--> *** $who_op <b>$DATA{'n'}</b> ($temp_ip).<br>\n";

close(FLAG);


$errors = " Ip mask: @ip[1].";



return $errors;



exit;