/*
Copyright (c) 2022 Criteo

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

package com.criteo.vips.options;

/**
 * Optional arguments for the "xyz" operation.
 */
public class XYZOptions {

	private Integer csize;
	private Integer dsize;
	private Integer esize;

	/**
	 * Optional argument: csize
	 * <p>
	 * Size of third dimension
	 * @return the value of {@code csize}
	 */
	public Integer getCsize() {
		return this.csize;
	}

	/**
	 * Set the optional "csize" argument.
	 * <p>
	 * Size of third dimension
	 * @param csize the new value of {@code csize}
	 */
	public void setCsize(Integer csize) {
		this.csize = csize;
	}

	/**
	 * Set the optional "csize" argument.
	 * <p>
	 * Size of third dimension
	 * @param csize the new value of {@code csize}
	 * @return this object for chaining
	 */
	public XYZOptions csize(Integer csize) {
		setCsize(csize);
		return this;
	}

	/**
	 * Optional argument: dsize
	 * <p>
	 * Size of fourth dimension
	 * @return the value of {@code dsize}
	 */
	public Integer getDsize() {
		return this.dsize;
	}

	/**
	 * Set the optional "dsize" argument.
	 * <p>
	 * Size of fourth dimension
	 * @param dsize the new value of {@code dsize}
	 */
	public void setDsize(Integer dsize) {
		this.dsize = dsize;
	}

	/**
	 * Set the optional "dsize" argument.
	 * <p>
	 * Size of fourth dimension
	 * @param dsize the new value of {@code dsize}
	 * @return this object for chaining
	 */
	public XYZOptions dsize(Integer dsize) {
		setDsize(dsize);
		return this;
	}

	/**
	 * Optional argument: esize
	 * <p>
	 * Size of fifth dimension
	 * @return the value of {@code esize}
	 */
	public Integer getEsize() {
		return this.esize;
	}

	/**
	 * Set the optional "esize" argument.
	 * <p>
	 * Size of fifth dimension
	 * @param esize the new value of {@code esize}
	 */
	public void setEsize(Integer esize) {
		this.esize = esize;
	}

	/**
	 * Set the optional "esize" argument.
	 * <p>
	 * Size of fifth dimension
	 * @param esize the new value of {@code esize}
	 * @return this object for chaining
	 */
	public XYZOptions esize(Integer esize) {
		setEsize(esize);
		return this;
	}

}
