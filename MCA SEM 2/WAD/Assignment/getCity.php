<?php 
include 'dataClass.php';
    $dc = new Dataclass();
    if (isset($_POST['state'])) {

    $state = $_POST['state'];

    $cmpd = $dc->getTable("select * from cities where state_id = $state");
    $res = "<option value='0'> Select City </option>";
    while ($cmprw = mysqli_fetch_assoc($cmpd)) {
        $res .= "<option value='".$cmprw['city_id']."'>".$cmprw['name']."</option>";
    }

    echo $res;

    }

 ?>