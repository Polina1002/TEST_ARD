#ifndef _ROS_SERVICE_SolveIKPose_h
#define _ROS_SERVICE_SolveIKPose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_control/Pose.h"

namespace arm_control
{

static const char SOLVEIKPOSE[] = "arm_control/SolveIKPose";

  class SolveIKPoseRequest : public ros::Msg
  {
    public:
      uint32_t initialState_length;
      typedef float _initialState_type;
      _initialState_type st_initialState;
      _initialState_type * initialState;
      typedef arm_control::Pose _goal_type;
      _goal_type goal;

    SolveIKPoseRequest():
      initialState_length(0), st_initialState(), initialState(nullptr),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->initialState_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->initialState_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->initialState_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->initialState_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->initialState_length);
      for( uint32_t i = 0; i < initialState_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->initialState[i]);
      }
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t initialState_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      initialState_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      initialState_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      initialState_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->initialState_length);
      if(initialState_lengthT > initialState_length)
        this->initialState = (float*)realloc(this->initialState, initialState_lengthT * sizeof(float));
      initialState_length = initialState_lengthT;
      for( uint32_t i = 0; i < initialState_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_initialState));
        memcpy( &(this->initialState[i]), &(this->st_initialState), sizeof(float));
      }
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return SOLVEIKPOSE; };
    virtual const char * getMD5() override { return "56b7bdf2e3497ef4b61f71d47b5139e0"; };

  };

  class SolveIKPoseResponse : public ros::Msg
  {
    public:
      uint32_t solution_length;
      typedef float _solution_type;
      _solution_type st_solution;
      _solution_type * solution;
      typedef int32_t _result_type;
      _result_type result;

    SolveIKPoseResponse():
      solution_length(0), st_solution(), solution(nullptr),
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->solution_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->solution_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->solution_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->solution_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->solution_length);
      for( uint32_t i = 0; i < solution_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->solution[i]);
      }
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
      uint32_t solution_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      solution_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      solution_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      solution_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->solution_length);
      if(solution_lengthT > solution_length)
        this->solution = (float*)realloc(this->solution, solution_lengthT * sizeof(float));
      solution_length = solution_lengthT;
      for( uint32_t i = 0; i < solution_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_solution));
        memcpy( &(this->solution[i]), &(this->st_solution), sizeof(float));
      }
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

    virtual const char * getType() override { return SOLVEIKPOSE; };
    virtual const char * getMD5() override { return "e07e5d27c1fe96089a2e6cb0bdc511c8"; };

  };

  class SolveIKPose {
    public:
    typedef SolveIKPoseRequest Request;
    typedef SolveIKPoseResponse Response;
  };

}
#endif
