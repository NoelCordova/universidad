var xmlhttp = new XMLHttpRequest();
xmlhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
        var myObj = JSON.parse(this.responseText);
        Morris.Donut({
        	element: 'GraphPastel',
			data: [
    			{label: "PRI", value: myObj[0]},
    			{label: "PAN", value: myObj[1]},
    			{label: "MORENA", value: myObj[2]},
    			{label: "PRD", value: myObj[3]},
    			{label: "NULO", value: myObj[4]}
  			],
  			resize: true
		});
    }
};
xmlhttp.open("GET", "../App.Modelo/VotosModelo.php?q=0", true);
xmlhttp.send(); 