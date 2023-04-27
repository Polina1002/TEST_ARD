#ifndef _ROS_arm_control_Pose_h
#define _ROS_arm_control_Pose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arm_control
{

  class Pose : public ros::Msg
  {
    public:
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _z_type;
      _z_type z;
      uint32_t rotx_length;
      typedef float _rotx_type;
      _rotx_type st_rotx;
      _rotx_type * rotx;
      uint32_t roty_length;
      typedef float _roty_type;
      _roty_type st_roty;
      _roty_type * roty;
      uint32_t rotz_length;
      typedef float _rotz_type;
      _rotz_type st_rotz;
      _rotz_type * rotz;

    Pose():
      x(0),
      y(0),
      z(0),
      rotx_length(0), st_rotx(), rotx(nullptr),
      roty_length(0), st_roty(), roty(nullptr),
      rotz_length(0), st_rotz(), rotz(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      offset += serializeAvrFloat64(outbuffer + offset, this->z);
      *(outbuffer + offset + 0) = (this->rotx_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rotx_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->rotx_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->rotx_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rotx_length);
      for( uint32_t i = 0; i < rotx_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->rotx[i]);
      }
      *(outbuffer + offset + 0) = (this->roty_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->roty_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->roty_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->roty_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->roty_length);
      for( uint32_t i = 0; i < roty_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->roty[i]);
      }
      *(outbuffer + offset + 0) = (this->rotz_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rotz_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->rotz_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->rotz_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rotz_length);
      for( uint32_t i = 0; i < rotz_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->rotz[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->z));
      uint32_t rotx_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      rotx_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      rotx_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      rotx_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->rotx_length);
      if(rotx_lengthT > rotx_length)
        this->rotx = (float*)realloc(this->rotx, rotx_lengthT * sizeof(float));
      rotx_length = rotx_lengthT;
      for( uint32_t i = 0; i < rotx_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_rotx));
        memcpy( &(this->rotx[i]), &(this->st_rotx), sizeof(float));
      }
      uint32_t roty_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      roty_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      roty_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      roty_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->roty_length);
      if(roty_lengthT > roty_length)
        this->roty = (float*)realloc(this->roty, roty_lengthT * sizeof(float));
      roty_length = roty_lengthT;
      for( uint32_t i = 0; i < roty_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_roty));
        memcpy( &(this->roty[i]), &(this->st_roty), sizeof(float));
      }
      uint32_t rotz_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      rotz_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      rotz_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      rotz_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->rotz_length);
      if(rotz_lengthT > rotz_length)
        this->rotz = (float*)realloc(this->rotz, rotz_lengthT * sizeof(float));
      rotz_length = rotz_lengthT;
      for( uint32_t i = 0; i < rotz_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_rotz));
        memcpy( &(this->rotz[i]), &(this->st_rotz), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "arm_control/Pose"; };
    virtual const char * getMD5() override { return "098ea279d162da9763a6edc61767f6d1"; };

  };

}
#endif
