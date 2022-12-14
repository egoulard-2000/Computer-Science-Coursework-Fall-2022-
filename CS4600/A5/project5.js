// Emile Goulard
// uID: u1244855
// CS4600 - Project 5
// 11/11/2022

// This function takes the translation and two rotation angles (in radians) as input arguments.
// The two rotations are applied around x and y axes.
// It returns the combined 4x4 transformation matrix as an array in column-major order.
// You can use the MatrixMult function defined in project5.html to multiply two 4x4 matrices in the same format.
function GetModelViewMatrix( translationX, translationY, translationZ, rotationX, rotationY )
{
	// From previous assignment
	var rotationZ = 0;
	
	var R1x = Math.cos(rotationZ)*Math.cos(rotationY);
	var R2x = Math.cos(rotationZ)*Math.sin(rotationY)*Math.sin(rotationX) - Math.sin(rotationZ)*Math.cos(rotationX);
	var R3x = Math.cos(rotationZ)*Math.sin(rotationY)*Math.cos(rotationX) + Math.sin(rotationZ)*Math.sin(rotationX);
	
	var R1y = Math.sin(rotationZ)*Math.cos(rotationY);
	var R2y = Math.sin(rotationZ)*Math.sin(rotationY)*Math.sin(rotationX) + Math.cos(rotationZ)*Math.cos(rotationX);
	var R3y = Math.sin(rotationZ)*Math.sin(rotationY)*Math.cos(rotationX) - Math.cos(rotationZ)*Math.sin(rotationX);
	
	var R1z = -Math.sin(rotationY);
	var R2z = Math.cos(rotationY)*Math.sin(rotationX);
	var R3z = Math.cos(rotationY)*Math.cos(rotationX);
	
	var trans = [
		R1x, R1y, R1z, 0,
		R2x, R2y, R2z, 0,
		R3x, R3y, R3z, 0,
		translationX, translationY, translationZ, 1
	];
	var mv = trans;
	return mv;
}

class MeshDrawer
{
	// The constructor is a good place for taking care of the necessary initializations.
	constructor()
	{
		// Compile the shader program
		this.prog = InitShaderProgram(meshVS, meshFS);
		
		// Get the ids of the uniform variables in the shaders
		this.mv = gl.getUniformLocation( this.prog, 'mv' ); // model view matrix
		this.mvp = gl.getUniformLocation( this.prog, 'mvp' );
		
		// Get the the vertex attributes in the shaders
		this.vertPos = gl.getAttribLocation( this.prog, 'pos' );
		this.txc = gl.getAttribLocation( this.prog, 'txc' );
		
		this.hasTexture = gl.getUniformLocation( this.prog, 'hasTexture' );
		this.canSwapYZ = gl.getUniformLocation( this.prog, 'swapYZ' );
		
		// Project 5 implementation for setting up shading variables
		this.normal = gl.getUniformLocation( this.prog, 'normal' );
		this.vertNormal = gl.getAttribLocation( this.prog, 'vertNormal' );
		this.alpha = gl.getUniformLocation( this.prog, 'alpha' );
		this.lightDir = gl.getUniformLocation( this.prog, 'lightDir' );
		
		this.vertBuffer = gl.createBuffer();
		this.texcoordBuffer = gl.createBuffer();
		this.normalBuffer = gl.createBuffer();
	}
	
	// This method is called every time the user opens an OBJ file.
	// The arguments of this function is an array of 3D vertex positions,
	// an array of 2D texture coordinates, and an array of vertex normals.
	// Every item in these arrays is a floating point value, representing one
	// coordinate of the vertex position or texture coordinate.
	// Every three consecutive elements in the vertPos array forms one vertex
	// position and every three consecutive vertex positions form a triangle.
	// Similarly, every two consecutive elements in the texCoords array
	// form the texture coordinate of a vertex and every three consecutive 
	// elements in the normals array form a vertex normal.
	// Note that this method can be called multiple times.
	setMesh( vertPos, texCoords, normals )
	{
		// Update the contents of the vertex buffer objects.
		this.numTriangles = vertPos.length / 3;

		// Set Object
		gl.bindBuffer( gl.ARRAY_BUFFER, this.vertBuffer );
		gl.bufferData( gl.ARRAY_BUFFER, new Float32Array(vertPos), gl.STATIC_DRAW );
		
		// Set Texture
		gl.bindBuffer( gl.ARRAY_BUFFER, this.texcoordBuffer );
		gl.bufferData( gl.ARRAY_BUFFER, new Float32Array(texCoords), gl.STATIC_DRAW );
		
		// Set Normals
		gl.bindBuffer( gl.ARRAY_BUFFER, this.normalBuffer );
		gl.bufferData( gl.ARRAY_BUFFER, new Float32Array(normals), gl.STATIC_DRAW );
	}
	
	// This method is called when the user changes the state of the
	// "Swap Y-Z Axes" checkbox. 
	// The argument is a boolean that indicates if the checkbox is checked.
	swapYZ( swap )
	{
		// Set the uniform parameter(s) of the vertex shader
		gl.useProgram(this.prog);
		if(swap)
		{
			gl.uniform1f(this.canSwapYZ, 1.0); 
		}
		else
		{
			gl.uniform1f(this.canSwapYZ, 0.0); 
		}
	}
	
	// This method is called to draw the triangular mesh.
	// The arguments are the model-view-projection transformation matrixMVP,
	// the model-view transformation matrixMV, the same matrix returned
	// by the GetModelViewProjection function above, and the normal
	// transformation matrix, which is the inverse-transpose of matrixMV.
	draw( matrixMVP, matrixMV, matrixNormal )
	{
		// WebGL initializations
		gl.useProgram( this.prog );
		gl.uniformMatrix3fv( this.normal, false, matrixNormal );
		gl.uniformMatrix4fv( this.mvp, false, matrixMVP );
		gl.uniformMatrix4fv( this.mv, false, matrixMV );
		
		// Bind and set the 3D Vertex Coordinates
		gl.bindBuffer( gl.ARRAY_BUFFER, this.vertBuffer );
		gl.vertexAttribPointer( this.vertPos, 3, gl.FLOAT, false, 0, 0 );
		gl.enableVertexAttribArray( this.vertPos );
		
		// Bind and set the 2D Texture Coordinates 
		gl.bindBuffer( gl.ARRAY_BUFFER, this.texcoordBuffer );
		gl.vertexAttribPointer( this.txc, 2, gl.FLOAT, false, 0, 0 );
		gl.enableVertexAttribArray( this.txc );
		
		// Bind the normal buffer
		gl.bindBuffer(gl.ARRAY_BUFFER, this.normalBuffer);
		gl.vertexAttribPointer(this.vertNormal, 3, gl.FLOAT, false, 0, 0);
		gl.enableVertexAttribArray(this.vertNormal);

		gl.drawArrays( gl.TRIANGLES, 0, this.numTriangles );
	}
	
	// This method is called to set the texture of the mesh.
	// The argument is an HTML IMG element containing the texture data.
	setTexture( img )
	{
		// Bind the texture
		gl.activeTexture(gl.TEXTURE0);
		const mytex = gl.createTexture();
		gl.bindTexture(gl.TEXTURE_2D, mytex);
		
		// Set texture image data
		gl.texParameteri(
			gl.TEXTURE_2D,
			gl.TEXTURE_MAG_FILTER,
			gl.LINEAR
		);

		// You can set the texture image data using the following command.
		gl.texImage2D( gl.TEXTURE_2D, 0, gl.RGB, gl.RGB, gl.UNSIGNED_BYTE, img );
		
		gl.generateMipmap(gl.TEXTURE_2D);

		// For Using Texture in Fragment Shader
		gl.uniform1i(this.hasTexture, 0);
	}
	
	// This method is called when the user changes the state of the
	// "Show Texture" checkbox. 
	// The argument is a boolean that indicates if the checkbox is checked.
	showTexture( show )
	{
		// Set the uniform parameter(s) of the fragment shader to specify if it should use the texture.
		gl.useProgram(this.prog);
		if(show)
		{
			gl.uniform1f(this.hasTexture, 1.0); // Set hasTexture to 1
		}
		else
		{
			gl.uniform1f(this.hasTexture, 0.0); // Set hasTexture to 0
		}
	}
	
	// This method is called to set the incoming light direction
	setLightDir( x, y, z )
	{
		// Set the uniform parameter(s) of the fragment shader to specify the light direction.
		gl.useProgram( this.prog );
		gl.uniform3fv( this.lightDir, [x, y, z] );
	}
	
	// This method is called to set the shininess of the material
	setShininess( shininess )
	{
		// Set the uniform parameter(s) of the fragment shader to specify the shininess.
		gl.useProgram( this.prog );
		gl.uniform1f( this.alpha, shininess );
	}
}

// Vertex Shader for Mesh
var meshVS = `
	attribute vec3 pos;
	attribute vec2 txc;
	uniform mat4 mvp;
	varying vec2 texCoord;
	uniform float swapYZ;

	uniform mat4 mv;
	uniform mat3 normal;
	attribute vec3 vertNormal;

	varying vec4 lightPos;
	varying vec3 n;

	void main()
	{
		if(swapYZ > 0.5)
		{
			gl_Position = mvp * vec4(pos[0], pos[2], pos[1],1); // Swap the position
			
			n = normal * vec3(vertNormal[0], vertNormal[2], vertNormal[1]);
			lightPos = mv * vec4(pos[0], pos[2], pos[1], 1);
		}
		else
		{
			gl_Position = mvp * vec4(pos, 1); // Keep regular position
			
			n = normal * vertNormal;
			lightPos = mv * vec4(pos, 1);
		}
		
		texCoord = txc;
	}
`;

// Fragment shader for Mesh
var meshFS = `
	precision mediump float;
	uniform sampler2D tex;
	varying vec2 texCoord;
	uniform float hasTexture;

	uniform vec3 lightDir;
	uniform float alpha;

	varying vec4 lightPos;
	varying vec3 n;
	vec4 currentColor;

	void main()
	{
		
		vec3 ambientLight = currentColor.rgb * 0.3;
		vec3 lightColor = vec3(1, 1, 1);
		vec3 light = lightColor * dot(n, lightDir);
		
		vec3 w = normalize(lightDir - lightPos.xyz);
		vec3 specular = (pow(dot(n, w), alpha)/dot(n, lightDir))*vec3(1, 1, 1); // specular color is white
		
		if(hasTexture < 0.5)
		{
			currentColor = vec4(0.70, 0.70, 0.70, 0.70);
		}
		else
		{
			currentColor = texture2D(tex, texCoord);
		}
		
		gl_FragColor = vec4(ambientLight + (light * (specular + currentColor.rgb)), currentColor.a);
	}
`;