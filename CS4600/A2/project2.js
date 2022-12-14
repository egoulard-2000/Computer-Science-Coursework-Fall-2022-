//Emile Goulard
//uID: u1244855
//CS4600 - Project 2

// Returns a 3x3 transformation matrix as an array of 9 values in column-major order.
// The transformation first applies scale, then rotation, and finally translation.
// The given rotation value is in degrees.
function GetTransform( positionX, positionY, rotation, scale )
{
	//Variables for applying rotation in its matrix
	var pi = Math.PI;
	var rotationRadian = rotation * pi / 180; //conversion to radians given degrees
	
	//For rotation matrix
	var sinR = Math.sin(rotationRadian);
	var cosR = Math.cos(rotationRadian);
	
	/*
		Start setting up matrices from slides
	
		Column-Major Order:
		Array = [
			column 1,
			column 2,
			column 3
		];
	*/
	var transMatrix = [
		1, 0, 0, 
		0, 1, 0, 
		positionX, positionY, 1
	];
	
	var rotationMatrix = [
		cosR, sinR, 0, 
		-sinR, cosR, 0, 
		0, 0, 1
	];
	
	var scaleMatrix = [
		scale, 0, 0, 
		0, scale, 0, 
		0, 0, 1
	];
	
	//Apply First Transform on Rotation and Scale
	var transform1 = ApplyTransform(rotationMatrix, scaleMatrix);
	
	//Then apply translation to satisfy homogeneous coordinates
	var transform2 = transMatrix;

	return ApplyTransform(transform1, transform2);
}

// Returns a 3x3 transformation matrix as an array of 9 values in column-major order.
// The arguments are transformation matrices in the same format.
// The returned transformation first applies trans1 and then trans2.
function ApplyTransform( trans1, trans2 )
{
	//3x3 transformation matrix to start
	var transformMatrix = [
		0, 0, 0,
		0, 0, 0,
		0, 0, 0
	];
	
	//These perform a 3x3 matrix multiplication
	var dimension = 3;
	//Iterate through first matrix rows
	for(var i = 0; i < dimension; i++) {
		//Iterate through second matrix rows
		for(var j = 0; j < dimension; j++) {
			//Apply the sum of pairwise products
			var sum = 0;
			for(var k = 0; k < dimension; k++) {
				sum += trans1[dimension * i + k] * trans2[dimension * k + j];
			}
			transformMatrix[dimension * i + j] = sum;
		}
	}
	
	return transformMatrix;
}
