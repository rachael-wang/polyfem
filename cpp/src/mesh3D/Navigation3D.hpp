#pragma once

#include "Mesh3DStorage.hpp"

namespace poly_fem{
	namespace Navigation3D{

		struct Index{
			int vertex;
			int edge;
			int face;
			int face_corner;
			int element;
			int element_patch;
		};
		void prepare_mesh(Mesh3DStorage &M);
		// Retrieve the index (v,e,f,h) of one vertex incident to the given face and element
		Index get_index_from_element_face(const Mesh3DStorage &M, int hi, int lf, int lv = 0);

		// Navigation in a surface Mesh3DStorage
		Index switch_vertex(const Mesh3DStorage &M, Index idx);
		Index switch_edge(const Mesh3DStorage &M, Index idx);
		Index switch_face(const Mesh3DStorage &M, Index idx);
		Index switch_element(const Mesh3DStorage &M, Index idx);

		// Iterate in a Mesh3DStorage
		inline Index next_around_element(const Mesh3DStorage &M, Index idx) { return switch_element(M, switch_face(M, idx)); }
		inline Index next_around_face(const Mesh3DStorage &M, Index idx) { return switch_edge(M, switch_vertex(M, idx)); }
		inline Index next_around_edge(const Mesh3DStorage &M, Index idx) { return switch_vertex(M, switch_face(M, idx)); }
		inline Index next_around_vertex(const Mesh3DStorage &M, Index idx) { return switch_face(M, switch_edge(M, idx)); }

	} // namespace Navigation3D
} // namespace poly_fem
