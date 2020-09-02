<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Assignment 1 XT2</title>
	<link rel="stylesheet" type="text/css" href="main.css">
</head>
<body>
	<div class="box">
		<form method="POST" name="form1">
			<div>
				<input type="text" name="fname" autocomplete="off" placeholder="First Name">
			</div>
			<div>
				<input type="text" name="lname" autocomplete="off" placeholder="Last Name">
			</div>
			<div>
				<button class="submit" name="submit"> Submit </button>
			</div>
		</form>
	
		<?php
		if(isset($_POST['submit']))
		{
			if($_SERVER['REQUEST_METHOD'] === 'POST') {
				echo "<br>Method is POST";
				if($_REQUEST['fname']) {
					echo "<br>Using Request";
					echo "<br> Your First name : " . $_REQUEST['fname'];
				}
				if($_REQUEST['fname']) {
					echo "<br> Your First name : " . $_REQUEST['lname'];
				}
			}


			else if ($_SERVER['REQUEST_METHOD'] === 'GET') {
				echo "<br>Method is GET";	
				if($_REQUEST['fname']) {
					echo "<br>Using Request";
					echo "<br> Your First name : " . $_REQUEST['fname'];
				}
				if($_REQUEST['fname']) {
					echo "<br> Your First name : " . $_REQUEST['lname'];
				}
			}
		}
		?>
	</div>
</body>
</html>