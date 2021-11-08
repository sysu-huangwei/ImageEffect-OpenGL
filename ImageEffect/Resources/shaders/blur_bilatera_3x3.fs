precision highp float;

uniform sampler2D u_texture;
varying vec2 texcoordOut;
varying vec4 texcoordOutNear;

void main()
{
    vec4 srcColor = texture2D(u_texture, texcoordOut);
    
    float tolerance_factor = 5.2486386;
    
    vec4 nearColor;
    float colorDistance;
    float sampleWeight;
    
    vec4 sum = vec4(0.0);
    float sumWeight = 0.0;
    
    sampleWeight = 0.5;
    sumWeight += sampleWeight;
    sum += srcColor * sampleWeight;
    
    nearColor = texture2D(u_texture, texcoordOutNear.xy);
    colorDistance = min(distance(srcColor, nearColor) * tolerance_factor, 1.0);
    sampleWeight = 0.25 * (1.0 - colorDistance);
    sumWeight += sampleWeight;
    sum += nearColor * sampleWeight;
    
    nearColor = texture2D(u_texture, texcoordOutNear.zw);
    colorDistance = min(distance(srcColor, nearColor) * tolerance_factor, 1.0);
    sampleWeight = 0.25 * (1.0 - colorDistance);
    sumWeight += sampleWeight;
    sum += nearColor * sampleWeight;
    
    gl_FragColor = sum / sumWeight;
}
