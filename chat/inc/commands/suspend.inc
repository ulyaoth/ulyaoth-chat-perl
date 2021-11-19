#!/usr/bin/perl


if($command eq '/suspend' && $level < $staff_rank){
                
$errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;
        
}
        
@suspend = split(/\s+/, $DATA{'msg'});

$reason = $DATA{'msg'};

$reason =~ s/^\/suspend//;

$reason =~ s/\s+//;


$reason =~ s/^@suspend[1]//;


@suspend[1]=substr(@suspend[1],0,14);


unless(@suspend[2]){


$errors = " Syntax: /suspend [nick] [reason].";

return $errors;

exit;



}

if(!-e "$root/ops/ops/@suspend[1].db"){


$errors = " Error, user <b>@suspend[1]</b> is not an Operator.";

return $errors;

exit;

}

if(@suspend[1] eq $opsnick){


$errors = " Error, not allowed.";

return $errors;

exit;


}

if(-e "$root/suspend/@suspend[1].db"){


$errors = " Error, Operator <b>@suspend[1]</b> is already suspended.";

return $errors;

exit;

}


dbmopen(%SUS,"$root/ops/ops/@suspend[1].db",0777);

$dlevel = $SUS{'level'};

dbmclose(%SUS);

if($dlevel >= $comm_rank){

$errors = " Error, this action is not allowed. This Operator currently has comm status, you can not suspend comm Ops, you will have to lower their rank first.";

return $errors;

exit;

}


dbmopen(%D,"$root/suspend/@suspend[1].db",0777);


$D{'owner'} = $realnick;


$D{'suspend'} = "*** Operator <b>@suspend[1]</b> suspended by <b>$realnick</b> for ($reason). Time: $fulltime.";

$D{'out'} = "*** Operator <b>@suspend[1]</b> suspended for reason ($reason).";



dbmclose(%D);

dbmopen(%R,"$root/ops/ops/@suspend[1].db",0777);

$R{'record_suspends'}++;

dbmclose(%R);




$errors = " Operator <b>@suspend[1]</b> suspended.";



return $errors;

exit;