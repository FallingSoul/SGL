#ifndef __SGL_CORE_RENDERER_CAMERA__
#define __SGL_CORE_RENDERER_CAMERA__

#include <glm/glm.hpp>
#include <glm/common.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace sgl
{
	struct sglCameraViewAngles
	{
		float pitch{};
		float yaw{};
		float roll{};
		explicit sglCameraViewAngles(glm::vec3 directoin) { this->recalculate_from_direction(directoin); }
		glm::vec3 calculate_direction() const
		{
			glm::vec3 direction{0,0,1};
			float cos_pitch = glm::cos(this->pitch);
			float sin_pitch = glm::sin(this->pitch);
			float cos_yaw = glm::cos(this->yaw);
			float sin_yaw = glm::sin(this->yaw);



			direction.x = cos_pitch * sin_yaw;
			direction.y = -sin_pitch;
			direction.z = cos_pitch * cos_yaw;
			if (0 != this->roll)
			{
				float cos_roll = glm::cos(this->roll);
				float sin_roll = glm::sin(this->roll);
				direction.x = direction.x * cos_roll - direction.y * sin_roll;
				direction.y = direction.x * sin_roll + direction.y * cos_roll;
			}
			return glm::normalize(direction);
		}
		void recalculate_from_direction(glm::vec3 directoin)
		{
			this->pitch = 0.f;
			this->yaw = 0.f;
			this->roll = 0.f;
			directoin = glm::normalize(directoin);
			if (1 == directoin.y)this->pitch = glm::radians(90.f);
			else if (-1 == directoin.y)this->pitch = glm::radians(-90.f);
			else
			{
				//set roll = 0
				this->pitch = -glm::asin(directoin.y);
				this->yaw = glm::acos(directoin.z / glm::sqrt(1 - directoin.y * directoin.y));
			}
		}
	};
	struct sglCameraVec
	{
		glm::vec3 position{};
		glm::vec3 front{};
		glm::vec3 right{};
		glm::vec3 up{};
		sglCameraVec(const glm::vec3& position, const glm::vec3& target)
		{
			glm::vec3 negative_direction = glm::normalize(position - target);
			glm::vec3 right = glm::normalize((glm::cross(glm::vec3(0, 1, 0), negative_direction)));
			glm::vec3 up = glm::normalize(glm::cross(negative_direction, right));

			this->position = position;
			this->front = -negative_direction;
			this->right = right;
			this->up = up;
		}
	};
	struct sglCameraMat
	{
		glm::mat4 view_mat{1};
		glm::mat4 projection_mat{1};
		void recalculate_view(const glm::vec3& position, const glm::vec3& direction, const glm::vec3& up)
		{
			this->view_mat = glm::lookAt(position, position + direction, up);
		}
		void recalculate_ortho(float left, float right, float bottom, float top)
		{
			this->projection_mat = glm::ortho(left, right, bottom, top);
		}
		void recalculate_ortho(float left, float right, float bottom, float top, float z_near, float z_far)
		{
			this->projection_mat = glm::ortho(left, right, bottom, top, z_near, z_far);
		}
		void recalculate_perspective(float fovy, float aspect, float z_near, float z_far)
		{
			this->projection_mat = glm::perspective(fovy, aspect, z_near, z_far);
		}
	};
	class sglCamera
	{
	public:
		sglCamera(const glm::vec3& position,const sglCameraViewAngles& angles)
			:_vec(position, position + angles.calculate_direction()),_angles(angles)
		{
			this->update_view();
		}
		sglCamera(const sglCameraVec& vec)
			:_vec(vec),_angles(vec.front)
		{
			this->update_view();
		}
		void set_position(const glm::vec3& position)
		{
			this->_vec.position = position;
		}
		void set_view_angles(float pitch, float yaw, float roll)
		{
			this->_angles.pitch = pitch;
			this->_angles.yaw = yaw;
			this->_angles.roll = roll;
		}
		void turn(float pitch, float yaw, float roll)
		{
			this->_angles.pitch += pitch;
			this->_angles.yaw += yaw;
			this->_angles.roll += roll;
			this->_vec.front = this->_angles.calculate_direction();
		}
		void update_view()
		{
			this->_mat.recalculate_view(this->_vec.position, this->_vec.front, this->_vec.up);
		}
		void update_perspective_projection(float fovy,float aspect,float z_near,float z_far)
		{
			this->_mat.recalculate_perspective(fovy,aspect,z_near,z_far);
		}
		void update_othro_projection(float width,float height,float z_near,float z_far)
		{
			this->_mat.recalculate_ortho(-width / 2, width / 2, -height / 2, height / 2, z_near, z_far);
		}
	public:

		sglCameraVec get_vectors()const { return this->_vec; }
		sglCameraVec& get_vectors() { return this->_vec; }
		sglCameraViewAngles get_view_angles()const { return this->_angles; }
		sglCameraViewAngles& get_view_angles() { return this->_angles; }
		sglCameraMat get_matrices()const { return this->_mat; }

	private:
		sglCameraVec _vec;
		sglCameraMat _mat;
		sglCameraViewAngles _angles;
	};
}


#endif //!__SGL_CORE_RENDERER_CAMERA__