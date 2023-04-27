#ifndef _ROS_SERVICE_SolveFKPose_h
#define _ROS_SERVICE_SolveFKPose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_control/Pose.h"

namespace arm_control
{

static const char SOLVEFKPOSE[] = "arm_control/SolveFKPose";

  class SolveFKPoseRequest : public ros::Msg
  {
    public:
      uint32_t jointPositions_length;
      typedef float _jointPositions_type;
      _jointPositions_type st_jointPositions;
      _jointPositions_type * jointPositions;

    SolveFKPoseRequest():
      jointPositions_length(0), st_jointPositions(), jointPositions(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->jointPositions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->jointPositions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->jointPositions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->jointPositions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->jointPositions_length);
      for( uint32_t i = 0; i < jointPositions_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->jointPositions[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t jointPositions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      jointPositions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      jointPositions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      jointPositions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->jointPositions_length);
      if(jointPositions_lengthT > jointPositions_length)
        this->jointPositions = (float*)realloc(this->jointPositions, jointPositions_lengthT * sizeof(float));
      jointPositions_length = jointPositions_lengthT;
      for( uint32_t i = 0; i < jointPositions_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_jointPositions));
        memcpy( &(this->jointPositions[i]), &(this->st_jointPositions), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return SOLVEFKPOSE; };
    virtual const char * getMD5() override { return "730e1e3e6eb29501bae56546745b9c91"; };

  };

  class SolveFKPoseResponse : public ros::Msg
  {
    public:
      typedef arm_control::Pose _solution_type;
      _solution_type solution;
      typedef int32_t _result_type;
      _result_type result;

    SolveFKPoseResponse():
      solution(),
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->solution.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_result.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_result.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_result.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->solution.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_result.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_result.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_result.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    virtual const char * getType() override { return SOLVEFKPOSE; };
    virtual const char * getMD5() override { return "dcad5622c26bbf895d917a21e82df24e"; };

  };

  class SolveFKPose {
    public:
    typedef SolveFKPoseRequest Request;
    typedef SolveFKPoseResponse Response;
  };

}
#endif
