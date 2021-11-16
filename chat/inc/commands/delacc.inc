#!/usr/bin/perl

if ($command eq '/delacc' && $level < $admin_rank){

$errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

}

@del = split(/\s+/,$DATA{'msg'});


if (!$del[1]) {
 
 $errors = " syntax: /delacc [nick].";

return $errors;

exit;


}



if (!-e "$root/ops/ops/$del[1]") {

$errors = " ops account $del[1] does not exist.";

return $errors;

exit;

} else {

unlink ("$root/ops/ops/$del[1]");
unlink ("$root/opspreferences/$del[1]");
unlink ("$root/wait/$del[1].txt");
unlink ("$root/mail/$del[1].txt");
unlink ("$root/mail/igmail/$del[1].txt");


$errors = " ops account $del[1] successfuly deleted.";

return $errors;

exit;

   }





