//Emile Goulard
//uID: u1244855
//CS4600 - Assignment 1

// bgImg is the background image to be modified.
// fgImg is the foreground image.
// fgOpac is the opacity of the foreground image.
// fgPos is the position of the foreground image in pixels. It can be negative and (0,0) means the top-left pixels of the foreground and background are aligned.
function composite( bgImg, fgImg, fgOpac, fgPos )
{
	//background width and height
	var bgImgWidth = bgImg.width;
	var bgImgHeight = bgImg.height;
	
	//foreground width and height
	var fgImgWidth = fgImg.width;
	var fgImgHeight = fgImg.height;
	
	//Pixels
	var bgPixels = 4 * bgImgWidth * bgImgHeight;
	
	// get the pixel data as array
	var bottomData = bgImg.data;
	var topData = fgImg.data;

	//background image RGBA values
	var bgImgColor = bottomData;
	var bgImgAlpha = bgImg.data[3];
	
	//foreground image RGBA values
	var fgImgColor = topData;
	var fgImgAlpha = fgOpac; //fgImg.data[3];
	
	//a = af + (1-af)*ab formula for Alpha Blending
	var a = fgImgAlpha + (1 - fgImgAlpha) * bgImgAlpha;
	if(bgImgAlpha == 1)
		a = 1;
	
	//"c = af*cf + (1-af)*cb" formula for Alpha Blending
	var c = (fgImgAlpha * fgImgColor + (1 - fgImgAlpha) * bgImgAlpha * bgImgColor) / a;
	//Check to ensure no division by 0
	if(fgImgAlpha == 0 && bgImgAlpha == 0) {
		a = 0;
		c = 0;
	}
	
	//Compositing
	while(bgPixels--) {
		bottomData[bgPixels] = bottomData[bgPixels] * a + topData[bgPixels] * a;
	}

	// for(var i = 0; i < bottomData.length; i += 4) {
		// //topData[i] = bottomData[i] * fgPos.x * fgPos.y / 255;
		// //topData[i+1] = bottomData[i+1] * fgPos.x * fgPos.y / 255;
		// //topData[i+2] = bottomData[i+2*] * fgPos.x * fgPos.y / 255;
		// topData[i] = topData[i] + fgPos.x * fgPos.y / 255;
		// topData[i+1] = topData[i+1] + fgPos.x * fgPos.y / 255;
		// topData[i+2] = topData[i+2] + fgPos.x * fgPos.y / 255;
	// }
	
	bgImg.data = bottomData;
	fgImg.data = topData;
}