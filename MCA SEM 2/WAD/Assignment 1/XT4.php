<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Assignment 1 XT4</title>
	<link rel="stylesheet" type="text/css" href="main.css">
</head>
<body>
	<div class="box">
		<form method="POST">
			<div>
				<input type="number" name="rno" required placeholder="Student Roll No">
			</div>
			<div>
				<input type="text" name="sname" autocomplete="off" placeholder="Enter Student Name">
			</div>
			<div>
				<input type="number" name="m1" autocomplete="off" placeholder="Marks 1">
			</div>
			<div>
				<input type="number" name="m2" autocomplete="off" placeholder="Marks 2">
			</div>
			<div>
				<input type="number" name="m3" autocomplete="off" placeholder="Marks 3">
			</div>
			<div>
				<button class="submit" name="submit"> Submit </button>
			</div>
		</form>
	
		<?php
		if(isset($_POST['submit'])){
			if($_POST['rno'] == '' || is_nan($_POST['rno'])) {
				echo "Invalid Student Roll No.";
			}
			else if ($_POST['sname'] == '') {
				echo "Fill Student Name.";
			}
			else {
				$m1 = $_POST['m1'];
				$m2 = $_POST['m2'];
				$m3 = $_POST['m3'];
				if($m1 < 0 || $m1 > 100 || $m2 < 0 || $m2 > 100 || $m3 < 0 || $m3 > 100) {
					echo "<br>Marks Must be btween 0 to 100";
				} else {
					$tot = $m1 + $m2 + $m3;
					$per = $tot / 3;
					echo "<br>Total: " . number_format((float)$tot, 2, '.', ',');
					echo "<br>Percentage: " . number_format((float)$per, 2, '.', '');

					switch(1) {
						case ($per > 80): echo "<br>Distinction"; break;
						case ($per > 70): echo "<br>First Class"; break;
						case ($per > 60): echo "<br>Second Class"; break;
						case ($per > 50): echo "<br>Third Class"; break;
						case ($per > 35): echo "<br>Pass"; break;
						default: echo "<br>Fail"; break;
					}
				}
			}
		}
		?>
	</div>
</body>
</html>