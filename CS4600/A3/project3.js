//Emile Goulard
//uID: u1244855
//CS4600 - Project 3

class CurveDrawer {
	constructor()
	{
		this.prog   = InitShaderProgram( curvesVS, curvesFS );
		
		// Get the locations of attributes and uniform variables.
		// Setup for locations of uniform variables such as control points and function
		this.p0 = gl.getUniformLocation(this.prog, 'p0');
		this.p1 = gl.getUniformLocation(this.prog, 'p1');
		this.p2 = gl.getUniformLocation(this.prog, 'p2');
		this.p3 = gl.getUniformLocation(this.prog, 'p3');
		
		this.mvp = gl.getUniformLocation(this.prog, 'mvp');
		// Point at t
		this.vertT = gl.getAttribLocation(this.prog, 't');
		
		this.buffer = gl.createBuffer();
		
		// Initialize the attribute buffer
		this.steps = 100;
		var tv = [];
		for ( var i=0; i<this.steps; ++i ) {
			tv.push( i / (this.steps-1) );
		}
		
		// This is where we can create and set the contents of the vertex buffer object
		// for the vertex attribute we need.
		gl.bindBuffer(gl.ARRAY_BUFFER, this.buffer);
		gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(tv), gl.STATIC_DRAW);
		
	}
	setViewport( width, height )
	{
		// This is where we should set the transformation matrix.
		var matrix = [
			2/width, 0, 0, 0,
			0, -2/height, 0, 0,
			0, 0, 1, 0,
			-1, 1, 0, 1];
			
		gl.useProgram( this.prog );	// Bind the program
		
		// Set a uniform variable value.
		gl.uniformMatrix4fv(this.mvp, false, matrix);
	}
	updatePoints( pt )
	{		
		var newPoints = [];
		var numOfPoints = 4;
		for(var i = 0; i < numOfPoints; i++)
		{
			var x = pt[i].getAttribute("cx");
			var y = pt[i].getAttribute("cy");
			
			// push these new updated points in order to update the uniform variables
			newPoints.push(x);
			newPoints.push(y);
		}
		
		// Bind the program before you set a uniform variable value.
		gl.useProgram(this.prog);
		
		// The control points have changed, we must update corresponding uniform variables.
		gl.uniform2fv(this.p0, [newPoints[0], newPoints[1]]);
		gl.uniform2fv(this.p1, [newPoints[2], newPoints[3]]);
		gl.uniform2fv(this.p2, [newPoints[4], newPoints[5]]);
		gl.uniform2fv(this.p3, [newPoints[6], newPoints[7]]);
	}
	draw()
	{
		// This is where we give the command to draw the curve.
		gl.useProgram(this.prog);
		
		// Bind the program and set the vertex attribute.
		gl.useProgram( this.prog );
		gl.bindBuffer( gl.ARRAY_BUFFER, this.buffer );
		gl.enableVertexAttribArray( this.p0 );
		gl.enableVertexAttribArray( this.p1 );
		gl.enableVertexAttribArray( this.p2 );
		gl.enableVertexAttribArray( this.p3 );
		gl.vertexAttribPointer( this.p0, 2, gl.FLOAT, false, 0, 0 );
		gl.vertexAttribPointer( this.p1, 2, gl.FLOAT, false, 0, 0 );
		gl.vertexAttribPointer( this.p2, 2, gl.FLOAT, false, 0, 0 );
		gl.vertexAttribPointer( this.p3, 2, gl.FLOAT, false, 0, 0 );
		gl.drawArrays( gl.LINE_STRIP, 0, 50 );
	}
}

// Vertex Shader
var curvesVS = `
	attribute float t;
	uniform mat4 mvp;
	uniform vec2 p0;
	uniform vec2 p1;
	uniform vec2 p2;
	uniform vec2 p3;
	void main()
	{
		// Implement the Bezier Curve Cubic Function and update the Position of the curve
		gl_Position =  mvp * (pow(1.0 - t, 3.0) * vec4(p0, 0, 1) +3.0*pow(1.0 - t, 2.0)*t * vec4(p1, 0, 1) + 3.0*(1.0 - t)*pow(t, 2.0) * vec4(p2, 0, 1) + pow(t, 3.0) * vec4(p3, 0, 1));
	}
`;

// Fragment Shader
var curvesFS = `
	precision mediump float;
	void main()
	{
		gl_FragColor = vec4(1,0,0,1);
	}
`;