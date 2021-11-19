#!/usr/bin/perl



if($command eq '/restore' && $level < $staff_rank){



$errors = " Error, command $command not recognized, please use /help for a list of commands.";

        

return $errors;



exit;



}

@restore = split(/\s+/, $DATA{'msg'});

unlink("$root/suspend/@restore[1].db");


$errors = " Ops <b>@restore[1]</b> restored.";



return $errors;



exit;