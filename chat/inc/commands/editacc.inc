#!/usr/bin/perl



if ($command eq '/editacc' && $level < $admin_rank){


$errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

}



if($DATA{'opslevel'} > 200){

$errors = " Error, this action is not allowed.";

return $errors;

exit;

}




dbmopen(%S,"$root/ops/ops/$DATA{'opsnick'}.db",0777);


$S{'level'} = $DATA{'opslevel'};

$S{'id'} = $DATA{'opssid'};

$S{'realpassword'} = $DATA{'opspass'};

$S{'password'} = crypt($DATA{'opspass'}, "Cd");

$S{'name'} = $DATA{'opsname'};

$S{'surname'} = $DATA{'opssurname'};

$S{'country'} = $DATA{'opscountry'};

$S{'zipcode'} = $DATA{'opszip'};

$S{'street'} = $DATA{'opsstreet'};

$S{'phone'} = $DATA{'opsphone'};

$S{'email'} = $DATA{'opsemail'};

dbmclose(%S);


$errors = " Details for Ops account <b>$DATA{'opsnick'}</b> successfuly updated.";

return $errors;

exit;