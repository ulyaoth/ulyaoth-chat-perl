#!/usr/bin/perl



if($command eq '/deop' && $level < $comm_rank){



$errors = " Error, command $command not recognized, please use /help for a list of commands.";

        

return $errors;



exit;



}

@restore = split(/\s+/, $DATA{'msg'});

unlink("$root/deopped/@restore[1]");


$errors = " Ops <b>@restore[1]</b> re-opped.";



return $errors;



exit;









