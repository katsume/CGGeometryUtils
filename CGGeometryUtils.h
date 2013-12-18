#ifndef CGGeometryUtils_h
#define CGGeometryUtils_h

#include <CoreGraphics/CGGeometry.h>

CG_INLINE CGSize CGSizeReverse(CGSize size) {
	
	return CGSizeMake(size.height,
					  size.width);
}

CG_INLINE CGSize CGSizeScaleAspectFit(CGSize source, CGSize target) {
	
	CGFloat scaleX= target.width/source.width;
	CGFloat scaleY= target.height/source.height;
	
	if(scaleX<scaleY){
		
		return CGSizeMake(target.width,
						  ceilf(source.height*scaleX));
	} else {
		
		return CGSizeMake(ceilf(source.width*scaleY),
						  target.height);
	}
}

CG_INLINE CGSize CGSizeScaleAspectFill(CGSize source, CGSize target) {
	
	CGFloat scaleX= target.width/source.width;
	CGFloat scaleY= target.height/source.height;
	
	if(scaleX>scaleY){
		
		return CGSizeMake(target.width,
						  ceilf(source.height*scaleX));
	} else {
		
		return CGSizeMake(ceilf(source.width*scaleY),
						  target.height);
	}
}

CG_INLINE CGRect CGRectScaleAspectFit(CGSize source, CGSize target) {
	
	CGSize size= CGSizeScaleAspectFit(source, target);
	
	return CGRectMake((target.width-size.width)/2,
					  (target.height-size.height)/2,
					  size.width,
					  size.height);
}

CG_INLINE CGRect CGRectScaleAspectFill(CGSize source, CGSize target) {
	
	CGSize size= CGSizeScaleAspectFill(source, target);
	
	return CGRectMake((target.width-size.width)/2,
					  (target.height-size.height)/2,
					  size.width,
					  size.height);
}

#endif
