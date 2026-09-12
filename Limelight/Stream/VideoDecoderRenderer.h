//
//  VideoDecoderRenderer.h
//  Moonlight
//
//  Created by Cameron Gutman on 10/18/14.
//  Copyright (c) 2014 Moonlight Stream. All rights reserved.
//

@import AVFoundation;

#import "AnyVideoDecoderRenderer.h"

@interface VideoDecoderRenderer : NSObject <AnyVideoDecoderRenderer>
- (id)initWithView:(UIView*)view callbacks:(id<ConnectionCallbacks>)callbacks streamAspectRatio:(float)aspectRatio useFramePacing:(BOOL)useFramePacing;

// Vision Villa: render into any sample-buffer sink (an AVSampleBufferVideoRenderer feeding a
// RealityKit VideoMaterial, or an AVSampleBufferDisplayLayer) instead of a StreamView.
// Same decode and enqueue path as the view-based renderer, so no added latency.
- (id)initWithSampleBufferSink:(id<AVQueuedSampleBufferRendering>)sink callbacks:(id<ConnectionCallbacks>)callbacks useFramePacing:(BOOL)useFramePacing;

- (void)setupWithVideoFormat:(int)videoFormat width:(int)videoWidth height:(int)videoHeight frameRate:(int)frameRate;
- (void)start;
- (void)stop;
- (void)setHdrMode:(BOOL)enabled;

- (int)submitDecodeBuffer:(unsigned char *)data length:(int)length bufferType:(int)bufferType decodeUnit:(PDECODE_UNIT)du;

@end
