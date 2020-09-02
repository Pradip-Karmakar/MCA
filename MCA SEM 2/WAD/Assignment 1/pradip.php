<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Exam WAD Pradip</title>
	<style>
		body{
			width: 100%;
			background-color:cyan;
		}
		.box{
			margin: 0 auto;
		}
	</style>
</head>
<body style="">
	<div class="box">
	<?php

		$ticket = array ("Silver" => 120, "Gold" => 180, "Platinum" => 230);
		$ticketsort =  $ticket;

		echo "<table border=1 style='border-radius:5px'> <tr> <td colspan='2'> Sort By Name <br></td></tr>";

		ksort($ticketsort);
		foreach($ticketsort as $key=>$value)
		{
			echo "<tr> <td>" . $key . " </td><td> " . $value . "</td></tr>"; 
		}
		echo "</table>";
	?>
	</div>
</body>
</html>

