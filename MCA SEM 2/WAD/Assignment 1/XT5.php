<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Assignment 1 XT5</title>
	<link rel="stylesheet" type="text/css" href="main.css">
</head>
<body>
	<div class="box">
		<form method="POST">
			<div>
				<input type="text" name="sname" autocomplete="off" placeholder="Enter The Name" required>
			</div>
			<div>
				<button class="submit" name="submit"> Submit </button>
			</div>
		</form>
	
		<?php
		if(isset($_POST['submit'])) {
			if ($_POST['sname'] == '') 
			{ 
				echo "Fill The Name"; 
			} 
			else {
				$f1 = @fopen('files/studinfo.txt', 'a+b');
				$sname = "\r\n" . $_POST['sname'];
				$fwrite = fwrite($f1, $sname);
				if($fwrite === false) {
					echo "Fail To Register Name."; 
				} else {
					echo "Name Registered Successfully. " . $fwrite . " bytes written.";
				}
				fclose($f1); 
			} 
		}
		?>
	</div>
</body>
</html>
