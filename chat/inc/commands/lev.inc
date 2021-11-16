#!/usr/bin/perl


if ($command eq '/lev' && $level < $staff_rank){


$errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

}



@lev = split(/\s+/, $DATA{'msg'});

unless(@lev[2]){

$errors = " Syntax: /lev [nick] [1-15].";

return $errors;

       exit;

}



if(@lev[2] < 1 or @lev[2] > 15){

$errors = " Syntax: /lev [nick] [1-15].";

return $errors;

       exit;

}

if(!-e "$root/ops/ops/@lev[1]"){
        close(ES);

$errors = " Error, Operator <b>@lev[1]</b> does not exist.";

return $errors;

       exit;


}

dbmopen(%U,"$root/ops/ops/@lev[1]",0777);

if($U{'level'} >= $comm_rank){

dbmclose(%U);

$errors = " Error, this action is NOT allowed.";

return $errors;

       exit;

}


open(LOG,">>$root/boards/record.txt");

print LOG "<b>*** Ops $realnick changed level seetings for Ops $lev[1] from rank $U{'level'} to rank @lev[2]. Time: $fulltime Room: $room.</b><br>\n";

close(LOG);

$U{'original_level'} = $U{'level'};

$U{'level'} = @lev[2];

dbmclose(%U);

$errors = " Level settings for Ops account <b>@lev[1]</b> successfuly updated. You will have to post message on committee board and inform other members about your action even thought this action will be logged for further monitoring.";

return $errors;

  exit;



